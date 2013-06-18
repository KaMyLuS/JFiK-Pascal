#include "File.h"
#include "Bit.h"

File::File(string name, bool write)
{
	if(write) file_st.open(name.c_str(), fstream::out | fstream::binary);
	else file_st.open(name.c_str(), fstream::in | fstream::binary);

	if(file_st.is_open()) 
	{
		open = true;
		file_st.seekg (0, ios::end);
		length = static_cast<int>(file_st.tellg());
		file_st.seekg (0, ios::beg);

		content = new char[length+1];
		file_st.read(content, length);
	}
	else open = false;

}

File::~File()
{
	file_st.close();
	delete [] content;
}

bool File::isOpen() const
{
	if(!open) return 0;
	return 1;
}

int File::get_length() const
{
	return length;
}

bool File::get_bit(int pos) const
{
	if(pos < 1 || pos > 8*this->get_length() )
	{
		//if(pos/8-1 > 660430) cout << (pos/8-1) << endl;
		throw error_bit_range();
	}
	if(pos%8 == 0) return bit::get_bit(content[pos/8-1], 8);
	return bit::get_bit(content[pos/8], pos%8);
}

char File::get_byte(int pos) const
{
	if(pos < 0 || pos >= length)
	{
		throw error_byte_range();
	}
	return content[pos];
}

char* File::get_bytes(int pos, int len) const
{
	return content+pos;
}

char* File::get_bytes_to_end(int pos) const
{
	return content+pos;
}

char* File::get_content() const
{
	return content;
}
