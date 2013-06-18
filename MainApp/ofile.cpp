#include "ofile.h"

ofile::ofile(string name)
{
	file.open(name.c_str(), ofstream::binary);
}

void ofile::writeString(string text)
{
	file.write(text.c_str(), text.size());
}

void ofile::writeChar(char c)
{
	char *temp = new char[1];
	temp[0] = c;
	file.write(temp, 1);
	delete[] temp;
}

bool ofile::isOpen() 
{
	return file.is_open();
}
