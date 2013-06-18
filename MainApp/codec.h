#ifndef CODEC_H_
#define CODEC_H_

#include <iostream>
#include "key.h"
#include <gmpxx.h>
#include <string>
using namespace std;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)

const int ALP_SIZE = 256; // rozmiar alfabetu

// klasa kodujaco-dekodujaca

class codec
{
	private:
		string input, output; // tekst wejsciowy i wyjsciowy
		int k, l; // dlugosc bloku tekstu wejsciowego i wyjsciowego
		bool ok; // czy utworzenie obiektu poszlo zgodnie z planem

	public:
		// kostruktor
		codec(string in, key rkey, int _k, int _l, bool enc = 1); 

		// pobieranie danych
		string get_input() const; // pobieranie tekstu wejsciowego
		string get_output() const; // pobieranie tekstu wyjsciowego
		int get_lenInBlock() const; // pobranie dlugosci bloku tekstu wejsciowego (k)
		int get_lenOutBlock() const; // pobranie dlugosci bloku tekstu wyjciowego (l)
		bool isOk() const; // czy utworzenie obiektu poszlo zgodnie z planem
};

#endif
