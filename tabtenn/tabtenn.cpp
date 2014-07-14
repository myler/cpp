#include <iostream>
#include "tabtenn.h"

TableTennisPlayer::TableTennisPlayer(const string &fn,
	const string &ln, bool ht) : first_name(fn), 
	last_name(ln), has_table(ht) {}

void TableTennisPlayer::Name() const
{
	std::cout << last_name << ", " << first_name;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn,
	const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
	: TableTennisPlayer(tp), rating(r) {}