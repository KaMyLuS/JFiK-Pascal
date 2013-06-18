#include "HFile.h"
#include "File.h"
#include <fstream>

//------------------------------------------------
// Konstruktory i destruktory
//------------------------------------------------

HFile::HFile(string name)
{
	File* f = new File(name, 0);
	header = f->get_bytes(0, 3);
	c_char = int(f->get_byte(3));
	if(c_char == 0) c_char = 256;
	c_nodes = 2*c_char - 1;
	pre_order = f->get_bytes(4, c_nodes/8+1);
	over_bits = int(f->get_byte(c_nodes/8+5));
	chars = f->get_bytes(c_nodes/8+5+1, c_char);
	code = f->get_bytes_to_end(c_nodes/8+6+c_char);
	code_len = f->get_length()-(c_nodes/8+6+c_char);
}

HFile::HFile(HTreePlain* tree)
{
	header = "\1H\2";
	c_nodes = tree->countNodes();
	c_char = tree->countChars();
	pre_order = tree->getPreOrder();
	chars = tree->getChars();
	code = tree->getEncoded();
	over_bits = tree->getOverBits();
	code_len = tree->getEncLen();
}

//-----------------------

char* HFile::getCode() const
{
	return code;
}

char* HFile::getChars() const
{
	return chars;
}

char* HFile::getPreOrder() const
{
	return pre_order;
}

int HFile::getCChar() const
{
	return c_char;
}

int HFile::getOverBits() const
{
	return over_bits;
}

int HFile::getCodeLen() const
{
	return code_len;
}


bool HFile::SaveToFile(string name) 
{
	ofstream out(name.c_str(), ofstream::binary);
	if(out.is_open())
	{
		out << header << char(c_char); 
		out.write(pre_order, (c_nodes>>3)+1);
		out << char(over_bits);
		out.write(chars, c_char);
		out.write(code, code_len);
		out.close();
		return 1;
	}
	return 0;
}

