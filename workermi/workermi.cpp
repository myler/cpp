#include "workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Data() const
{
	cout << "Name: " << full_name <<endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, full_name);
	cout << "Enter worker's ID: ";
	cin >> id;
	while(cin.get() != '\n') {
	    continue;
	}
}

void Waiter::Set()
{
	cout << "Enter Waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Category: Waiter" << endl;
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter Waiter's panache rating: ";
	cin >> panache;
	while(cin.get() != '\n') {
	    continue;
	}
}

char *Singer::pv[Singer::Vtypes] = { 
		"other", 
		"alto", 
		"contralto",
		"soprano",
		"bass",
		"baritone",
		"tenor" };

void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "Category: singer" << endl;
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Enter number for singer's vocal range:" << endl;
	int i;
	for (i = 0; i < Vtypes; ++i)
	{
		cout << i << ": " << pv[i] << "\t";
		if (i % 4 == 3)
		{
			cout << endl;
		}
	}
	if (i % 4 != 0)
	{
		cout << endl;
	}
	cin >> voice;
	while(cin.get() != '\n') {
	    continue;
	}
}

void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category: singing waiter" << endl;
	Worker::Data();
	Data();
}