#ifndef HTE_H_
#define HTE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include "Bit.h"
#include "Node.h"

using namespace std;

typedef long long int LL;

class HTreeEnc // drzewo utworzone z ZAKODOWANEGO tekstu
{
	private:
		int c_nodes, c_chars; // ile wezlow i ile znakow
		char *pre_order, *chars; // zapis (binarny) pre order oraz znaki w drzewie
		char *plain; // tekst zwykly
		int pl_len; // dlugosc tekstu zwyklego
		char *encoded; // tekst zakodowany (binarnie)
		int enc_len; // dlugosc zakodowanego
		int over_bits; // nadmiar bitow wynikajacy z koniecznosci zapisu calych bajtow
		Node* root; // korzen
		bool alloc; // czy udalo sie wszystko zaalokowac
		HTreeEnc operator=(const HTreeEnc &T);
		HTreeEnc(const HTreeEnc &T);

	public:
		HTreeEnc(char* porder, char* chrs, int cchars, char* enc, int en_len, int ov_bit); // tworzenie drzewa z zakodowanego tekstu i zapisu pre order
		~HTreeEnc();

		int countNodes() const;
		int countChars() const;
		Node* getRoot() const;
		char* getPreOrder() const;
		char* getChars() const;
		char *getPlain() const;
		char *getEncoded() const;
		int getPlainLen() const;
		int getEncLen() const;
		int getOverBits() const;
		bool isGood() const;

		void setRoot();
};

namespace HTEUtils
{
	void preOrderMT(Node* x, char *pre, char *chrs);
}

#endif
