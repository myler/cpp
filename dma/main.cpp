#include <iostream>
#include "dma.h"

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::endl;

	base_DMA shirt("Portabelly", 8);
	lacks_DMA balloon("red", "Blimpo", 4);
	has_DMA maps("Mercator", "Buffalo Keys", 5);

	cout << "Displaying base_DMA object:" << endl;
	cout << shirt << endl;
	cout << "Displaying lacks_DMA object:" << endl;
	cout << balloon << endl;
	cout << "Displaying has_DMA object:" << endl;
	cout << maps << endl;

	lacks_DMA balloon_2(balloon);
	cout << "Result of lacks_DMA copy:" << endl;
	cout << balloon_2 << endl;

	has_DMA maps_2;
	maps_2 = maps;
	cout << "Result of has_DMA assignment:" << endl;
	cout << maps_2 << endl;

	return 0;
}