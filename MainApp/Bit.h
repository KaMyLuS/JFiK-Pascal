#ifndef BIT_H_
#define BIT_H_

#include <string>
#include <iostream>
using namespace std;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define abs(a) ((a)<0 ? -(a) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

// funkcje do obs³ugi bitow, bity numerowane od 0, od lewej do prawej
// bajty numerujemy od 0

typedef long long int LL;

namespace bit
{
	bool get_bit(char byte, int pos);
	bool get_bit(char* bytes, LL pos);
	char set_bit(char byte, int pos, bool bit);
	void set_bit(char *bytes, LL pos, bool bit);
	string BytesToStr(char *bytes, int len);
};

#endif
