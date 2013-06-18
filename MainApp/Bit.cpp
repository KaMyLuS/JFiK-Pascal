#include "Bit.h"

bool bit::get_bit(char byte, int pos)
{
	return static_cast<bool>(byte & (1 << (8-pos)));
}

char bit::set_bit(char byte, int pos, bool bit)
{
	return bit ? (byte | (1 << (8-pos))) : (byte & ~(1 << (8-pos)));
}

void bit::set_bit(char *bytes, LL pos, bool bit)
{
	LL ind = pos >> 3;
	if(pos%8 == 0) ind--;
	bytes[ind] = set_bit(bytes[ind], (pos%8 == 0 ? 8 : pos%8), bit);
}

bool bit::get_bit(char *bytes, LL pos)
{
	LL ind = pos >> 3;
	if(pos%8 == 0) ind--;
	return get_bit(bytes[ind], (pos%8 == 0 ? 8 : pos%8));
}

string bit::BytesToStr(char *bytes, int len)
{
	string wyn = "";
	REP(i, len)
	{
		FOR(j, 1, 8)
		{
			if(get_bit(bytes[i], j)) wyn += '1';
			else wyn += '0';
		}
	}
	return wyn;
}
