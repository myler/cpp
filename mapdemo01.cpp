#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	multimap<int, string> coll;

	coll = {
		{5, "tagged"},
		{2, "a"},
		{1, "this"},
		{4, "of"},
		{6, "strings"},
		{1, "is"},
		{3, "multimap"}
	};

	for (auto& elem : coll) {
		cout << elem.first << ": " << elem.second << endl;
	}

	return 0;
}