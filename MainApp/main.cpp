#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#include "pascal_driver.hpp"

#include "gen_key.h"
#include "codec.h"
#include "key.h"
#include "ifile.h"
#include "ofile.h"

#include "HFile.h"
#include "File.h"
#include "quicklz.h"

int key_len = 64, files_count, sum;
string file_names[10];

bool gen_keys, scan, parse, huff_compress, lz_compress, decompress, encode, decode;
bool parse_res = 1;

int main(int argc, char *argv[])
{
	// wczytywanie i analiza parametrow
	if(argc > 1 && argc < 8)
	{
		if(strcmp(argv[1], "-gen") == 0)
		{
			if(argc < 4)
			{
				cout << "Niepoprawne uzycie aplikacji. Prosze jej uzywac zgodnie z instrukcja!" << endl;
				return 0;
			}
			else
			{
				// nazwy plikow klucza publicznego i prywatnego
				file_names[0] = argv[2];
				file_names[1] = argv[3];
				files_count = 2;
				
				if(argc == 5) key_len = atoi(argv[4]);
				if(key_len <= 8) key_len = 64;
				
				gen_keys = 1;
			}
		}
		else
		{
			for(int i = 1; i < argc; i++)
			{
				if(strcmp(argv[i], "-s") == 0)
				{
					scan = 1;
				}
				else if(strcmp(argv[i], "-p") == 0)
				{
					parse = 1;
				}
				else if(strcmp(argv[i], "-ch") == 0)
				{
					huff_compress = 1;
				}
				else if(strcmp(argv[i], "-clz") == 0)
				{
					lz_compress = 1;
				}
				else if(strcmp(argv[i], "-dco") == 0)
				{
					decompress = 1;
					scan = parse = 0;
				}
				else if(strcmp(argv[i], "-enc") == 0)
				{
					encode = 1;
				}
				else if(strcmp(argv[i], "-dec") == 0)
				{
					decode = 1;
					scan = parse = 0;
				}
				else
				{
					file_names[files_count++] = argv[i];
				}
			}
		}
    }
    else
    {
        cout << "Niepoprawne uzycie aplikacji. Prosze jej uzywac zgodnie z instrukcja!" << endl;  
		return 0;
    }	
	
	sum = gen_keys + huff_compress + lz_compress + decompress + encode + decode;
	if(sum > 1)
	{
		cout << "Niepoprawne uzycie aplikacji. Prosze jej uzywac zgodnie z instrukcja!" << endl;  
		return 0;
	}
	
	if(gen_keys)
	{
		if(file_names[0] == file_names[1])
		{
			cout << "Blad! Nazwy plikow sie powtarzaja!" << endl;
			return 0;
		}
			
		gen_key keys(key_len, key_len);
		ofstream of(file_names[0].c_str(), ofstream::binary);
		if(of.is_open())
		{
			of << "\1RSK\2" << endl;
			of << keys.get_pub().get_k()  << ' ' << keys.get_pub().get_l() << endl;
			of << keys.get_pub().get_n().get_str() << endl;
			of << keys.get_pub().get_d().get_str()  << endl;
			of.close();
		}
		else
		{
			cout << "Blad! Nie moge zapisac pliku z kluczem publicznym!" << endl;
			return 0;
		}

		ofstream of2(file_names[1].c_str(), ofstream::binary);
		if(of2.is_open())
		{
			of2 << "\1RSK\2" << endl;
			of2 << keys.get_priv().get_k() << ' ' << keys.get_priv().get_l() << endl;
			of2 << keys.get_priv().get_n().get_str()  << endl;
			of2 << keys.get_priv().get_d().get_str()  << endl;
			of2.close();
		}
		else
		{
			cout << "Blad!! Nie moge zapisac pliku z kluczem prywatnym!" << endl;
			return 0;
		}

		cout << "Klucze zostaly poprawnie zapisane" << endl;
		return 0;
	}
	
	if(parse)
	{
		Pascal::Pascal_Driver driver;
		parse_res = driver.parse(file_names[0].c_str());
	}
	else if(scan)
	{
		Pascal::Pascal_Driver driver;
		parse_res = driver.scan(file_names[0].c_str());
	}
	
	if(parse_res)
	{
		if(huff_compress)
		{
			if(file_names[0] == file_names[1])
			{
				cout << "Blad! Nazwy plikow sie powtarzaja!" << endl;
				return 0;
			}
			
			File *in = new File(file_names[0]);
			if(in->isOpen() && in->get_length())
			{
				HTreePlain *tree = new HTreePlain(in->get_content(), in->get_length());		
				if(tree->isGood())
				{
					HFile *f = new HFile(tree);
					if(f->SaveToFile(file_names[1])) cout << "Kompresja zakonczona pomyslnie" << endl;
					else cout << "Blad! Zapis do pliku nie powiodl sie!" << endl;
				}
				else
				{
					cout << "Wystapil blad podczas kompresji!" << endl;
				}
			}
			else
			{
				cout << "Blad otwarcia pliku " << file_names[0] << "!" << endl;
			}
			delete in;
		}
		else if(lz_compress)
		{
			if(file_names[0] == file_names[1])
			{
				cout << "Blad! Nazwy plikow sie powtarzaja!" << endl;
				return 0;
			}
			
			ifstream in(file_names[0].c_str(), ifstream::binary);
			int len, len2;
			char* src, *dst;
			if(in.is_open())
			{
				ofstream out(file_names[1].c_str(), ofstream::binary);
				if(out.is_open())
				{
					qlz_state_compress *state_compress = new qlz_state_compress;
					in.seekg (0, ios::end);
					len = static_cast<int>(in.tellg());
					in.seekg (0, ios::beg);
					src = new char[len];
					dst = new char[len+400];
					in.read(src, len);
					len2 = qlz_compress(src, dst, len, state_compress);
					out.write("\1L\2", 3);
					out.write(dst, len2);
					out.close();
					delete state_compress;
					
					cout << "Pomyslnie skompresowano plik" << endl;
				}
				else
				{
					cout << "Blad! Zapis do pliku nie powiodl sie!" << endl;
				}
				
				delete [] src;
				delete [] dst;

			}
			else
			{
				cout << "Blad otwarcia pliku " << file_names[0] << "!" << endl;
			}
		}
		else if(decompress)
		{
			if(file_names[0] == file_names[1])
			{
				cout << "Blad! Nazwy plikow sie powtarzaja!" << endl;
				return 0;
			}
			
			File *in = new File(file_names[0]);
			if(in->isOpen() && in->get_length() > 3)
			{
				char head[3];
				head[0] = in->get_byte(0);
				head[1] = in->get_byte(1);
				head[2] = in->get_byte(2);
				if(head[0] == '\1' && head[1] == 'H' && head[2] == '\2')
				{
					cout << "Plik " << file_names[0] << " skompresowany algorytmem Huffmana\n" << endl;
					delete in;
					HFile *f2 = new HFile(file_names[0]);
					HTreeEnc *t2 = new HTreeEnc(f2->getPreOrder(), f2->getChars(), f2->getCChar(), f2->getCode(), f2->getCodeLen(), f2->getOverBits());
					if(t2->isGood())
					{
						ofstream f3(file_names[1].c_str(), ofstream::binary);
						if(f3.is_open())
						{
							f3.write(t2->getPlain(), t2->getPlainLen());
							f3.close();
							cout << "Pomyslnie zdekompresowano plik" << endl;
						}
						else
						{
							cout << "Blad! Zapis do pliku nie powiodl sie!" << endl;
						}
					}
					else
					{
						cout << "Blad! Nie jest mozliwa dekompresja" << endl;
					}
				}
				else if(head[0] == '\1' && head[1] == 'L' && head[2] == '\2')
				{
					int len;
					char *dst;
					qlz_state_decompress *state_decompress = new qlz_state_decompress;
					cout << "Plik " << file_names[0] << " skompresowany algorytmem LZ\n" << endl;
					ofstream out(file_names[1].c_str(), ofstream::binary);
					if(out.is_open())
					{
						len = qlz_size_decompressed(in->get_bytes_to_end(3));
						dst = new char[len];
						len = qlz_decompress(in->get_bytes_to_end(3), dst, state_decompress);
						out.write(dst, len);
						out.close();
						cout << "Dekompresja zakonczona sukcesem" << endl;
					}
					else
					{
						cout << "Blad! Zapis do pliku nie powiodl sie!" << endl;
					}
					
					delete [] dst;
					delete state_decompress;
				}
				else
				{
					cout << "Wczytany plik " << file_names[0] << " nie jest plikiem skompresowanym obslugiwanym algorytmem!"
						 << endl;
				}
			}
			else
			{
				cout << "Blad! Nie moge otworzyc pliku " << file_names[0] << "!" << endl;
				delete in;
			}
		}
		else if(encode)
		{
			if(file_names[0] == file_names[1] || file_names[0] == file_names[2])
			{
				cout << "Blad! Nazwy plikow sie powtarzaja!" << endl;
				return 0;
			}
			
			ifile infile(file_names[0].c_str());
			if(infile.isOpen() && infile.get_length() > 0)
			{
				ifstream iff(file_names[2].c_str(), ifstream::binary);
				if(iff.is_open())
				{
					string temp = "\1RSK\2";
					string head;
					getline(iff, head);
					bool ok = 1;
					if(head.size() >= 5) 
					{
						REP(i, 5) 
							if(temp[i] != head[i]) ok = 0;
					}
					else ok = 0;

					if(ok)
					{
						int k, l;
						string _n, _d;
						iff >> k >> l;
						iff >> _n;
						iff >> _d;
						mpz_class n(_n);
						mpz_class d(_d);

						key pub(n, d, k, l);

						codec enc(infile.get_content(), pub, pub.get_k(), pub.get_l());
						ofile outfile(file_names[1].c_str());
						if(outfile.isOpen())
						{
							outfile.writeString("\1RSA\2");
							outfile.writeString(enc.get_output());
							cout << "Zaszyfrowany plik zostal zapisany" << endl;
						}
						else cout << "Blad! Nie moge zapisac zaszyfrowanego pliku !" << endl;
					}
					else cout << "Blad! Podany plik " << file_names[2] << " nie jest kluczem publicznym!" << endl;
				}
				else cout << "Blad! Nie moge otworzyc pliku " << file_names[2] << "!" << endl;
			}
			else cout << "Blad! Nie moge otworzyc pliku " << file_names[0] << "!" << endl;			
		}
		else if(decode)
		{
			if(file_names[0] == file_names[1] || file_names[0] == file_names[2])
			{
				cout << "Blad! Nazwy plikow sie powtarzaja!" << endl;
				return 0;
			}
			
			ifile infile(file_names[0].c_str());
			if(infile.isOpen() && infile.get_length() > 5 )
			{
				string temp = "\1RSA\2";
				bool ok = 1;
				REP(i, 5) if(infile.get_byte(i) != temp[i]) ok = 0;
				if(!ok) 
				{
					cout << "Blad! Podany plik " << file_names[0] << " nie jest plikiem zaszyfrowanym algorytmem RSA!" << endl;
					return 0;
				}

				ifstream iff(file_names[2].c_str(), ifstream::binary);
				if(iff.is_open())
				{
					string temp = "\1RSK\2";
					string head;
					getline(iff, head);
					bool ok = 1;
					if(head.size() >= 5) 
					{
						REP(i, 5) 
							if(temp[i] != head[i]) ok = 0;
					}
					else ok = 0;

					if(ok)
					{
						int k, l;
						string _n, _d;
						iff >> k >> l;
						iff >> _n;
						iff >> _d;
						mpz_class n(_n);
						mpz_class d(_d);

						key priv(n, d, k, l);

						codec dec(infile.get_bytesToEnd(5), priv, priv.get_k(), priv.get_l(), 0);
						ofile outfile(file_names[1].c_str());
						if(outfile.isOpen())
						{
							outfile.writeString(dec.get_output());
							cout << "Odszyfrowany plik zostal zapisany" << endl;
						}
						else cout << "Blad! Nie moge zapisac do pliku! " << endl << endl;
					}
					else cout << "Blad! Podany plik " << file_names[2] << " nie jest kluczem prywatnym!" << endl;
				}
				else cout << "Blad! Nie moge otworzyc pliku " << file_names[2] << "!" << endl;
			}
			else cout << "Blad! Nie moge otworzyc pliku " << file_names[0] << "!" << endl;		
		}
	}
	else
	{
		cout << "Plik nie przeszedl poprawnie procesu skanowania/parsowania, zatem nie jest mozliwe wykonanie kolejnych dzialan!" << endl;
	}
}
