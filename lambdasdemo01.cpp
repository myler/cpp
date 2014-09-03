#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<double> v {1.0, 2.0, 3.0, 4.0, 5.0};

	transform(v.begin(), v.end(),
		v.begin(),
		[](double d) {
			if ((int)d % 2 == 0)
				return d * d - (d - 1) * (d - 1);
			else
				return d * d * d - 3 * d;
		});

	copy(v.begin(), v.end(),
		ostream_iterator<double>(cout, " "));
	cout << endl;

	return 0;
}