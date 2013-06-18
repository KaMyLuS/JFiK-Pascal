#include "codec.h"

codec::codec(string in, key rkey, int _k, int _l, bool enc)
{
	// inicjalizacja odpowiednich zmiennych i wartosci
	k = _k;
	l = _l;
	mpz_t _nk, _nl;
	mpz_init(_nk);
	mpz_init(_nl);
	mpz_ui_pow_ui(_nk, ALP_SIZE, k);
	mpz_ui_pow_ui(_nl, ALP_SIZE, l);
	mpz_class nk = mpz_class(_nk);
	mpz_class nl = mpz_class(_nl);

	// sprawdzamy czy liczby k i l sa dobrze dobrane
	if(((nk >= rkey.get_n() || nl <= rkey.get_n()) && enc) || ((nk <= rkey.get_n() || nl >= rkey.get_n()) && !enc) )
	{
		// zle dobrane
		ok = 0;
	}
	else 
	{
		input = in;
		output = "";
		int ovchars = int(in[0]+128)*256 + int(in[1]+128);

		int i = (enc ? 0 : 2);
		// szyfrujemy/deszyfrujemy tekst blok po bloku
		while(i < input.size())
		{
			// liczymy hash dla kazdego bloku
			mpz_class hash = 0, pow_alp = 1;
			FORD(j, i+k-1, i)
			{
				if(j < input.size()) 
				{
					hash += pow_alp*int(input[j]+128);
					//cout << int(input[j]) << ' ' << pow_alp*int(input[j]) << ' ' << hash << endl;
				}
				/*else // brakuje tekstu
				{
					hash += pow_alp*(ALP_SIZE-1);
				}*/
				pow_alp *= ALP_SIZE;
			}
			//cout << "hash input: " << hash << endl;

			// obliczamy zaszyfrowany hash
			mpz_powm(_nk, hash.get_mpz_t(), rkey.get_d().get_mpz_t(), rkey.get_n().get_mpz_t()); 
			hash = mpz_class(_nk);
			//cout << "hash output: " << hash << endl;
			//cout << "---" << endl;

			// zamieniamy zaszyfrowany hash na blok tekstu
			int j = l;
			string block = ""; 
			while(j--)
			{
				mpz_class modb = hash%ALP_SIZE;
				int mods = modb.get_ui();
				//if(mods < ALP_SIZE-1)
				{
					block = char(mods-128) + block; 
				}
				//else cout << "DUPA" << endl;
				hash /= ALP_SIZE;
			}
			output += block;
			i += k;
		}

		// usuwamy niepotrzebne znaki z konca
		if(!enc && ovchars) output = output.substr(0, output.size() - ovchars);

		// dopisujemy informacje o nadmiarze znakow
		if(enc)
		{
			int ovc = k-(in.size()%k == 0 ? k : in.size()%k);
			//cout << ovc << endl;
			string y = "";
			y = char(ovc%256-128) + y;
			ovc /= 256;
			y = char(ovc%256-128) + y;
			output = y + output;
		}

		// informujemy o powodzeniu
		ok = 1;
	}
}

string codec::get_input() const
{
	return input;
}

string codec::get_output() const
{
	return output;
}

int codec::get_lenInBlock() const
{
	return k;
}

int codec::get_lenOutBlock() const
{
	return l;
}

bool codec::isOk() const
{
	return ok;
}
