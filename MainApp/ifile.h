#ifndef IFILE_H_
#define IFILE_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)

// klasa do czytania z pliku

class ifile
{
	private:
		ifstream file;
		string content;

	public:
		ifile(string name);

		string get_content() const;
		string get_bytes(int from, int len) const;
		string get_bytesToEnd(int from) const;
		char get_byte(int byte) const;
		int get_length() const;
		bool isOpen();
};

#endif
