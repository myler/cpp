#ifndef TABTENN_H
#define TABTENN_H

#include <string>

using std::string;

class TableTennisPlayer
{
private:
	string first_name;
	string last_name;
	bool has_table;
public:
	TableTennisPlayer(const string &fn = "none",
		const string &ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const { return has_table; }
	void ResetTable(bool v) { has_table = v; }
};

class RatedPlayer : public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string &fn = "none", 
		const string &ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
	unsigned int Rating() const { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
};

#endif // TABTENN_H
