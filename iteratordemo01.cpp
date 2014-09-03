#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> coll;

	copy(istream_iterator<string>(cin),
		istream_iterator<string>(),
		back_inserter(coll));

	sort(coll.begin(), coll.end());

	unique_copy(coll.begin(), coll.end(),
		ostream_iterator<string>(cout, "\n"));

	return 0;
}