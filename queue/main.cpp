#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;
bool new_customer(double x);

int main(int argc, char const *argv[])
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller" << endl;
	cout << "Enter maxinum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cycle_limit = MIN_PER_HR * hours;

	cout << "Enter the average number of customers per hour: ";
	double per_hour;
	cin >> per_hour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / per_hour;

	Item temp;
	long turn_aways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	long wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cycle_limit; ++cycle)
	{
		if (new_customer(min_per_cust))
		{
			if (line.is_full())
			{
				turn_aways++;
			} else {
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}

		if (wait_time <= 0 && !line.is_empty())
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}

		if (wait_time > 0)
		{
			wait_time--;
		}

		sum_line += line.queue_count();
	}

	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "\tcustomers served: " << served << endl;
		cout << "\t\tturn_ways: " << turn_aways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double) sum_line / cycle_limit << endl;
		cout << " average wait time: " << (double) line_wait / served << " minutes." << endl;
	} else {
		cout << "No customers!" << endl;
	}
	cout << "Done!" << endl;

	return 0;
}

bool new_customer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}