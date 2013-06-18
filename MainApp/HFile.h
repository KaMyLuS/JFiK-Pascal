#ifndef HFILE_H_
#define HFILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include "HTreePlain.h"
#include "HTreeEnc.h"

using namespace std;

class HFile
{
	private:
		string header;
		int c_nodes, c_char, over_bits, code_len; // ilosc wezlow w drzewie, ilosc znakow, nadmiar bitow, dlugosc zakodowanego tekstu
		char* pre_order, *chars, *code; // binarny zapis pre order, znaki w tekscie oraz zakodowany tekst

	public:
		HFile(HTreePlain* tplain);
		HFile(string name);
		int getCNodes() const;
		int getCChar() const;
		char* getPreOrder() const;
		char* getChars() const;
		char* getCode() const;
		int getOverBits() const;
		int getCodeLen() const;
		bool SaveToFile(string name);
		string getHeader() const;
};

#endif
