#include "key.h"

key::key()
{
	n_len = d_len = 0;
	n = d = 0;
}

key::key(mpz_class _n, mpz_class _d, int _k, int _l)
{
	k = _k;
	l = _l;
	n = _n;
	d = _d;
	n_len = n.get_str().size();
	d_len = d.get_str().size();
}

mpz_class key::get_n() const
{
	return n;
}

mpz_class key::get_d() const
{
	return d;
}

int key::get_nlen() const
{
	return n_len;
}

int key::get_dlen() const
{
	return d_len;
}

int key::get_k() const
{
	return k;
}

int key::get_l() const
{
	return l;
}
