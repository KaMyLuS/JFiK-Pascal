#include "ifile.h"

ifile::ifile(string name)
{
	int len;
	char* buf;

	file.open(name.c_str(), ifstream::binary);
	if(file.is_open())
	{
		file.seekg (0, ios::end);
		len = file.tellg();
		file.seekg (0, ios::beg);

		buf = new char[len];
		file.read(buf, len);

		REP(i, len) content += buf[i];

		delete[] buf;
	}
}

string ifile::get_content() const
{
	return content;
}

string ifile::get_bytes(int from, int len) const
{
	return content.substr(from, len);
}

string ifile::get_bytesToEnd(int from) const
{
	return content.substr(from);
}

char ifile::get_byte(int byte) const
{
	return content[byte];
}

int ifile::get_length() const
{
	return content.size();
}

bool ifile::isOpen()
{
	return file.is_open();
}
