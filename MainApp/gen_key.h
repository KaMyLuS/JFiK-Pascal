#ifndef GEN_KEY_H_
#define GEN_KEY_H_

#include "key.h"
#include <iostream>
#include <gmpxx.h>

// klasa sluzaca do wygenerowania pary kluczy

class gen_key
{
	private:
		key priv, pub;

	public:
		// konstruktory
		gen_key(int pbits, int qbits); // utworzenie pary kluczy o liczbach p, q dlugosci pbits, qbits w bitach

		// pobieranie danych
		key get_priv() const; // pobranie klucza prywatnego
		key get_pub() const; // pobranie klucza publicznego
};

#endif
