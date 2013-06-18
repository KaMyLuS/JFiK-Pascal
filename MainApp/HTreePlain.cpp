//#include "Node.h"
#include "HTreePlain.h"
#include <queue>



//------------------------------------------------
// konstruktory/destruktory drzewa
//------------------------------------------------

HTreePlain::HTreePlain(char* s, int len)
{
	//inicjalizacja zmiennych
	priority_queue<Node*, vector<Node*>, NodePointCompare> pq;

	//priority_queue<int> x;
	
	char_count = new int[256];
	REP(i, 256) char_count[i] = 0;
	plain = s;
	pl_len = len;
	pre_order = chars = encoded = NULL;
	enc_len = over_bits = po_bit = i_c = c_chars = 0;

	REP(i, pl_len) char_count[int(plain[i])+128]++; // zliczamy wystapienia znakow

	//---------- tworzymy drzewo Huffmana
	REP(i, 256)
	{
		if(char_count[i])
		{
			c_chars++;
			Node *temp = new Node(1, char_count[i], char(i-128));	
			pq.push(temp);
		}
	}
	c_nodes = 2*c_chars - 1;

	while(pq.size() > 1)
	{
		Node *t1 = pq.top();
		pq.pop();
		Node *t2 = pq.top();
		pq.pop();

		Node *nowy = new Node(0, t1->getCount()+t2->getCount(), '\0', t1, t2);
		if(pq.empty()) setRoot(nowy);
		else pq.push(nowy);
	}
	if(pq.size()) setRoot(pq.top());
	//--------------
	
	// tworzymy kod pre order drzewa
	pre_order = new char[(c_nodes>>3) + 1];
	chars = new char[c_chars];
	HTPUtils::preOrderCT(root, pre_order, chars);
	//cout << "Jest preorder" << endl;

	// tworzymy tabelê kodów
	code_table = new string[256];
	if(c_nodes == 1) code_table[int(chars[0])+128] = "1";
	else
	{
		string code = "";
		HTPUtils::preOrderCode(root, code, code_table);
	}
	//cout << "Jest tablica kodow" << endl;

	// ustalamy d³ugoœæ zakodowanego tekstu
	LL len_temp = 0;
	REP(i, 256) if(char_count[i]) 
	{
		len_temp += LL(char_count[i])*code_table[i].size();
		//cout << "cc[i]: " << char_count[i] << endl;
	}
	//cout << enc_len << endl;
	if(len_temp%8) 
	{
		over_bits = 8-len_temp%8;
		enc_len = static_cast<int>((len_temp>>3) + 1);
	}
	else enc_len = static_cast<int>((len_temp>>3));
	alloc = 1;
	try 
	{
		//cout << enc_len << endl;
		encoded = new char[enc_len];
	}
	catch(bad_alloc)
	{
		alloc = 0;
	}
	if(alloc)
	{

		// i kodujemy
		LL bit = 1;
		int prg = pl_len/100+1;
		int perc = 0;
		REP(i, pl_len)
		{
			REP(j, static_cast<int>(code_table[int(plain[i])+128].size())) 
				bit::set_bit(encoded, bit++, code_table[int(plain[i])+128][j] == '1' ? 1 : 0);	
			if(i%prg == 0) 
			{
				int p2 = perc;
				while(p2 > 0)
				{
					p2 /= 10;
				}
			}
		}
	}
	else 
	{
		cout << "Blad alokacji pamieci - za duzy plik" << endl;
		//system("pause");
	}
	
}


HTreePlain::~HTreePlain()
{
	delete [] char_count;
	delete [] pre_order;
	delete [] chars;
	delete [] encoded;

}

//------------------------------------------------
// funkcje pobierajace dane z drzewa
//------------------------------------------------

string* HTreePlain::getCodeTable() const
{
	return code_table;
}

int HTreePlain::countNodes() const
{
	return c_nodes;
}

int HTreePlain::countChars() const
{
	return c_chars;
}

Node* HTreePlain::getRoot() const
{
	return root;
}

char* HTreePlain::getPreOrder() const
{
	return pre_order;
}

char* HTreePlain::getChars() const
{
	return chars;
}

int* HTreePlain::getCharsCountTable() const
{
	return char_count;
}

char* HTreePlain::getPlain() const
{
	return plain;
}

char* HTreePlain::getEncoded() const
{
	return encoded;
}

int HTreePlain::getPlainLen() const
{
	return pl_len;
}

int HTreePlain::getEncLen() const
{
	return enc_len;
}

int HTreePlain::getOverBits() const
{
	return over_bits;
}

bool HTreePlain::isGood() const
{
	return alloc;
}


//------------------------------------------------
// funkcje zmieniajace drzewo
//------------------------------------------------

void HTreePlain::setRoot(Node *x)
{
	root = x;
}

//--------------------------------------------------------
// funkcje pomocnicze dla drzewa
//--------------------------------------------------------


void HTPUtils::preOrderCT(Node *x, char *po_code, char *chars)
{
	static int bit_nr = 1;
	static int c_nr = 0;
	//cout << "bit nr: " << bit_nr << " c_nr: " << c_nr << endl;
	if(x->isLeaf())
	{
		bit::set_bit(po_code, bit_nr, 0);
		chars[c_nr++] = x->getChar();
		bit_nr++;
	}
	else
	{
		bit::set_bit(po_code, bit_nr, 1);
		bit_nr++;
		if(x->getLeft()) preOrderCT(x->getLeft(), po_code, chars);
		if(x->getRight())preOrderCT(x->getRight(), po_code, chars);
	}
}

void HTPUtils::preOrderCode(Node *x, string &code, string *table)
{
	if(x->isLeaf())
	{
		table[int(x->getChar())+128] = code;
		return;
	}
	if(x->getLeft())
	{
		code += '0';
		preOrderCode(x->getLeft(), code, table);
		code.erase(code.size()-1);
	}
	if(x->getRight())
	{
		code += '1';
		preOrderCode(x->getRight(), code, table);
		code.erase(code.size()-1);
	}	
}
