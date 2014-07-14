#include <iostream>
#include <array>

using namespace std;

int main(int argc, char const *argv[])
{
	array<int, 3> scores;
	cout << "Enter the first score: ";
	cin >> scores[0];
	cout << "Enter the second score: ";
	cin >> scores[1];
	cout << "Enter the third score: ";
	cin >> scores[2];

	cout << "The first score is " << scores[0] << ".\n";
	cout << "The second score is " << scores[1] << ".\n";
	cout << "The third score is " << scores[2] << ".\n";
	cout << "The average score is ";
	cout << ((double) (scores[0] + scores[1] + scores[2])) / 3 << ".\n";

	return 0;
}