#include <iostream>
#include "tv.h"

bool Tv::vol_up()
{
	if (volume < max_val)
	{
		volume++;

		return true;
	} else {
		return false;
	}
}

bool Tv::vol_down()
{
	if (volume > min_val)
	{
		volume--;

		return true;
	} else {
		return false;
	}
}

void Tv::chan_up()
{
	if (channel < max_channel)
	{
		channel++;
	} else {
		channel = 1;
	}
}

void Tv::chan_down()
{
	if (channel > 1)
	{
		channel--;
	} else {
		channel == max_channel;
	}
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;

	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = "
		<< (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = "
		<< (input == TV ? "TV" : "DVD") << endl;
	}
}