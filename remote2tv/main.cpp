#include <iostream>
#include "tv.h"

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::endl;

	Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.on_off();
	s42.chan_up();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.chan_up();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.vol_up(s42);
	grey.vol_up(s42);
	cout << "\n42\" settings after using remote:" << endl;
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:" << endl;
	s58.settings();

	return 0;
}