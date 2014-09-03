#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	list<int> coll;

	for (int i = 1; i <= 6; ++i) {
		coll.push_front(i);
		coll.push_back(i);
	}

	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout));
	cout << endl;

	remove(coll.begin(), coll.end(), 3);

	copy(coll.begin(), coll.end(),
		ostream_iterator<int>(cout));
	cout << endl;

	return 0;
}