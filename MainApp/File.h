#ifndef FILE_H_
#define FILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <Windows.h>

using namespace std;

class File
{
	private:
		int length;
		string file_name;
		fstream file_st;
		char* content;
		bool open;
		bool write;

	public:
		//konstruktory i testy
		File(string name, bool write = 0);
		~File();
		bool isOpen() const;
		
		//funkcje czytajace
		int get_length() const;
		bool get_bit(int pos) const;
		char get_byte(int pos) const;
		char* get_bytes(int pos, int len) const;
		char* get_bytes_to_end(int pos) const;
		char* get_content() const;

		//bledy:
		class error_open{}; // blad otwarcia pliku
		class error_bit_range{}; // bit spoza zakresu
		class error_byte_range{}; // bajt spoza zakresu
		class error_save{}; // blad zapisu pliku
		class error_read_only{}; // zapis do pliku tylko do odczytu
};

#endif
