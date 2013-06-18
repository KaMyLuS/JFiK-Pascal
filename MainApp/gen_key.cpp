#include "gen_key.h"
#include <gmpxx.h>
#include <ctime>
#include <iostream>

using namespace std;

gen_key::gen_key(int pbits, int qbits)
{
	if(pbits > 1 && qbits > 1)
	{
		// inicjujemy generator liczb pseudolosowych
		gmp_randstate_t stat;
		gmp_randinit_default(stat);
		gmp_randclass rand(gmp_randinit_default); 
		rand.seed(time(NULL));

		// losujemy liczby pierwsze p i q
		mpz_class p = rand.get_z_bits(pbits);
		mpz_t temp;
		mpz_init(temp);
		mpz_next_likely_prime(temp, p.get_mpz_t(), stat);
		p = mpz_class(temp);

		mpz_class q = rand.get_z_bits(qbits);
		mpz_next_likely_prime(temp, q.get_mpz_t(), stat);
		q = mpz_class(temp);

		// liczymy n i funkcje eulera
		mpz_class n = p*q;
		mpz_class phi = n + 1 - p - q;

		// losujemy liczbe e
		mpz_class e, tnwd;
		mpz_class t = 123456789;
		t *= 123456789;
		t *= 531;
		do
		{
			e = rand.get_z_range(min(phi, t));
			mpz_gcd(temp, phi.get_mpz_t(), e.get_mpz_t());
			tnwd = mpz_class(temp);
		}while(tnwd != 1); 

		// liczymy e^-1 mod phi
		mpz_class d;
		if(mpz_invert(temp, e.get_mpz_t(), phi.get_mpz_t())) d = mpz_class(temp);
		else cout << "ERROR - odwrotnosc modulo nie istnieje" << endl;

		// liczymy dlugosci blokow tekstu
		mpz_class nk = 256;
		int k = 1;
		while(nk*256 < n)
		{
			nk *= 256;
			k++;
		}

		// uzupelniamy dane kluczy
		priv = key(n, d, k+1, k);
		pub = key(n, e, k, k+1);

		//cout << p << "\n---\n" << q << "\n---\n" << n << "\n---\n" << phi << "\n---\n" << e << "\n---\n" << d << endl;
		//cout << endl;
		//cout << priv.get_nlen() << endl;
	}
}

key gen_key::get_priv() const
{
	return priv;
}

key gen_key::get_pub() const
{
	return pub;
}
