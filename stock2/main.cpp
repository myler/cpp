#include <iostream>
#include "stock2.h"

const int STKS = 4;

int main(int argc, char const *argv[])
{
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings: " << std::endl;
	for (int i = 0; i < STKS; ++i)
	{
		stocks[i].show();
	}

	const Stock *top = &stocks[0];
	for (int i = 0; i < STKS; ++i)
	{
		top = &top->top_val(stocks[i]);
	}

	std::cout << "\nMost valueable holdings:\n";
	top->show();
	
	return 0;
}