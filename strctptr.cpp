#include <iostream>
#include <cmath>

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

void rect_2_polar(const rect *pxy, polar *pda);
void show_polar(const polar *pda);

int main(int argc, char const *argv[])
{
	using namespace std;

	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while(cin >> rplace.x >> rplace.y) {
	    rect_2_polar(&rplace, &pplace);
	    show_polar(&pplace);
	    cout << "Next two numbers (q to quit): ";
	}
	cout << "Done." << endl;

	return 0;
}

void show_polar(const polar *pda)
{
	using namespace std;

	const double RAD_TO_DEG = 57.2929577951;
	
	cout << "distance = " << pda->distance;
	cout << ", angle = " << pda->angle * RAD_TO_DEG;
	cout << " degress" << endl;
}

void rect_2_polar(const rect *pxy, polar *pda)
{
	using namespace std;

	pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}