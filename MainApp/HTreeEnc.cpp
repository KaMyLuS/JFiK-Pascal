#include "Node.h"
#include "HTreeEnc.h"

//------------------------------------------------
// konstruktory/destruktory drzewa
//------------------------------------------------


HTreeEnc::HTreeEnc(char* porder, char* chrs, int cchars, char* enc, int en_len, int ov_bit)
{
	// inicjalizacja zmiennych
	chars = chrs;
	c_chars = cchars;
	c_nodes = 2*c_chars - 1;
	pre_order = porder;
	enc_len = en_len;
	over_bits = ov_bit;
	encoded = enc;
	plain = NULL;
	pl_len = 0;

	// dekodujemy
	alloc = 1;
	// przypadek jak jest tylko jeden znak
	if(c_nodes == 1)
	{
		root = new Node(1, 0, chars[0]);
		pl_len = 8*enc_len-over_bits;
		try 
		{
			plain = new char[pl_len];
		}
		catch(bad_alloc)
		{
			alloc = 0;
		}
		if(alloc)
		{
			FOR(i, 1, 8*enc_len-over_bits) plain[i-1] = chars[0];
		}
		else cout << "Blad alokacji pamieci - za duzy plik?" << endl;
	}
	// ogolny przypadek
	else
	{
		LL prg = (LL(8)*enc_len-over_bits)/100+1;
		LL perc = 0;
		root = new Node(0, 0, 0);
		HTEUtils::preOrderMT(root, pre_order, chars);
		LL i = 1;
		// obliczamy wynikowy rozmiar pliku
		while(i <= LL(8)*enc_len-over_bits)
		{
			Node* temp = root;
			while(!temp->isLeaf() && i <= LL(8)*enc_len-over_bits)
			{
				if(bit::get_bit(encoded, i)) temp = temp->getRight();
				else temp = temp->getLeft();
				i++;
				if(i%prg == 0) 
				{
					LL p2 = perc;
					while(p2 > 0)
					{
						p2 /= 10;
					}
				}
			}
			pl_len++;
		}
		i = 1;
		int j = 0;
		// proba alokacji pamieci
		try
		{
			plain = new char[pl_len];
		}
		catch(bad_alloc)
		{
			alloc = 0;
		}
		if(alloc)
		{
			// wlasciwa dekompresja
			prg = (LL(8)*enc_len-over_bits)/100+1;
			perc = 0;
			while(i <= LL(8)*enc_len-over_bits)
			{
				Node* temp = root;
				while(!temp->isLeaf() && i <= LL(8)*enc_len-over_bits)
				{
					if(bit::get_bit(encoded, i)) temp = temp->getRight();
					else temp = temp->getLeft();
					i++;
					if(i%prg == 0) 
					{
						LL p2 = perc;
						cout << "\b";
						while(p2 > 0)
						{
							p2 /= 10;
						}
					}
				}
				plain[j++] = temp->getChar();
			}
		}
		else cout << "Blad alokacji pamieci - za duzy plik?" << endl;
	}
}

HTreeEnc::~HTreeEnc()
{
	delete root;
	delete [] plain;
}

//------------------------------------------------
// funkcje czytaj¹ce z drzewa
//------------------------------------------------

int HTreeEnc::countNodes() const
{
	return c_nodes;
}

int HTreeEnc::countChars() const
{
	return c_chars;
}

Node* HTreeEnc::getRoot() const
{
	return root;
}

char* HTreeEnc::getPreOrder() const
{
	return pre_order;
}

char* HTreeEnc::getChars() const
{
	return chars;
}

char* HTreeEnc::getPlain() const
{
	return plain;
}

char* HTreeEnc::getEncoded() const
{
	return encoded;
}
int HTreeEnc::getPlainLen() const
{
	return pl_len;
}

int HTreeEnc::getEncLen() const
{
	return enc_len;
}

int HTreeEnc::getOverBits() const
{
	return over_bits;
}

bool HTreeEnc::isGood() const
{
	return alloc;
}

//------------------------------------------------
// funkcje pomocnicze dla drzewa
//------------------------------------------------

void HTEUtils::preOrderMT(Node* x, char *pre, char *ch)
{
	static int pbit = 1;
	static int ich = 0;
	if(!bit::get_bit(pre, pbit))
	{
		x->setLeaf(1);
		x->setChar(ch[ich++]);
		pbit++;
	}
	else
	{
		pbit++;
		if(!x->getLeft())
		{
			Node* temp = new Node(0, 0, '\0');
			x->setLeft(temp);
			preOrderMT(x->getLeft(), pre, ch);
		}
		if(!x->getRight())
		{
			Node* temp = new Node(0, 0, '\0');
			x->setRight(temp);
			preOrderMT(x->getRight(), pre, ch);
		}
	}
}
