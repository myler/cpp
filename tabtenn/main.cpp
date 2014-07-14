#include <iostream>
#include "tabtenn.h"

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::endl;

	TableTennisPlayer player_1("Tara", "Boomdea", false);
	RatedPlayer rplayer_1(1140, "Mallory", "Duck", true);

	rplayer_1.Name();
	if (rplayer_1.HasTable())
	{
		cout << ": has a table." << endl;
	} else {
		cout << ": hasn't a table." << endl;
	}

	player_1.Name();
	if (player_1.HasTable())
	{
		cout << ": has a table." << endl;
	} else {
		cout << ": hasn't a table." << endl;
	}

	cout << "Name: ";
	rplayer_1.Name();
	cout << "; Rating: " << rplayer_1.Rating() << endl;

	RatedPlayer rplayer_2(1212, player_1);
	rplayer_2.Name();
	cout << "; Rating: " << rplayer_2.Rating() << endl;

	return 0;
}