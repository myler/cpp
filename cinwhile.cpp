#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;

	char ch;
	cout << "The first word: ";
	while(cin.get(ch)) {
	    cout << ch;
	    if (ch == '\n')
	    {
	    	cout << "The next word: ";
	    }
	}
	cout << endl;

	return 0;
}