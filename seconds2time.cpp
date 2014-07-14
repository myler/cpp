#include <iostream>

const int MULTI_TIME = 60;
const int MULTI_DATE = 24;

int main(int argc, char const *argv[])
{
	using namespace std;

	int total_seconds;
	int days, hours, minutes, seconds;

	cout << "Enter the number of seconds: ";
	cin >> total_seconds;
	days = total_seconds / (MULTI_DATE * MULTI_TIME * MULTI_TIME);
	hours = (total_seconds % (MULTI_DATE * MULTI_TIME * MULTI_TIME)) 
			/ (MULTI_TIME * MULTI_TIME);
	minutes = ((total_seconds % (MULTI_DATE * MULTI_TIME * MULTI_TIME)) 
				% (MULTI_TIME * MULTI_TIME)) / MULTI_TIME;
	seconds = ((total_seconds % (MULTI_DATE * MULTI_TIME * MULTI_TIME)) 
				% (MULTI_TIME * MULTI_TIME)) % MULTI_TIME;
	cout << total_seconds << " seconds = " << days << " days, ";
	cout << hours << " hours, " << minutes << " minutes, " << seconds;
	cout << " seconds." << endl;

	return 0;
}