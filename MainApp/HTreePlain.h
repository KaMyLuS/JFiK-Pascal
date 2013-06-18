#ifndef HTP_H_
#define HTP_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include "Bit.h"
#include "Node.h"

using namespace std;

typedef long long int LL;

class HTreePlain // drzewo utworzone ze ZWYKLEGO tekst
{
	private:
		int c_nodes, c_chars; // ile wezlow i ile znakow
		char *pre_order, *chars; // zapis (binarny) pre order oraz znaki w drzewie
		char *plain; // tekst zwykly
		int pl_len; // dlugosc tekstu zwyklego
		char *encoded; // tekst zakodowany (binarnie)
		int enc_len; // dlugosc zakodowanego
		int over_bits; // niedomiar bitow wynikajacy z koniecznosci zapisu calych bajtow
		Node* root; // korzen
		int* char_count;
		string* code_table;
		bool alloc; // czy udalo sie wszystko zaalokowac
		HTreePlain operator=(const HTreePlain &T);
		HTreePlain(const HTreePlain &T);
	
	public:
		HTreePlain(char* s, int len); // tworzenie drzewa z tekstu do zakodowania
		~HTreePlain();

		string* getCodeTable() const;
		int countNodes() const;
		int countChars() const;
		Node* getRoot() const;
		char* getPreOrder() const;
		char* getChars() const;
		int *getCharsCountTable() const;
		char *getPlain() const;
		char *getEncoded() const;
		int getPlainLen() const;
		int getEncLen() const;
		int getOverBits() const;
		bool isGood() const; // czy udalo sie utworzyc obiekt

		void setRoot(Node* x);

		int po_bit, i_c; // aktualny bit w tworzeniu kodu pre order oraz aktualny nr znaku
};

// funkcje pomocnicze dla drzewa

namespace HTPUtils
{
	void preOrderCT(Node *x, char *po_code, char *chars); // przejscie pre order dla zakodowania drzewa
	void preOrderCode(Node *x, string &code, string *table); // przejscie pre order dla uzyskania tablicy kodów
}

#endif
