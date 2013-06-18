#ifndef OFILE_H_
#define OFILE_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)

// klasa do zapisywania do pliku

class ofile
{
	private:
		ofstream file;

	public:
		ofile(string name);

		void writeString(string text);
		void writeChar(char c);
		bool isOpen();
};

#endif
