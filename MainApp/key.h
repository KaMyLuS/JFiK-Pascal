#ifndef KEY_H_
#define KEY_H_

#include <iostream>
#include <gmpxx.h>

// klasa obslugujaca klucze prywatne badz publiczne

class key
{
	private:
		mpz_class n, d; // para liczb do klucza
		int n_len, d_len; // dlugosci powyzszych liczb
		int k, l; // dlugosci blokow tekstu przed i po kodowaniem

	public:
		// kontruktory
		key(); // pusty klucz
		key(mpz_class _n, mpz_class _d, int _k, int _l); // utworzenie klucza z liczb _n i _d

		// pobieranie danych
		mpz_class get_n() const;
		mpz_class get_d() const;
		int get_nlen() const;
		int get_dlen() const;
		int get_k() const;
		int get_l() const;
};

#endif

