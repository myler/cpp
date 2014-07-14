#include <iostream>
#include <string>
#include "queuetp.h"

int main(int argc, char const *argv[])
{
	using std::string;
	using std::cout;
	using std::endl;
	using std::cin;

	QueueTP<string> cs(5);
	string temp;

	while(!cs.is_full()) {
	    cout << "Please enter your name. You will be "
	    "served in the order of arrival." << endl;
	    cout << "name: ";
	    getline(cin, temp);
	    cs.enqueue(temp);
	}
	cout << "The queue is full. Processing begins!" << endl;

	while(!cs.is_empty()) {
	    cs.dequeue(temp);
	    cout << "Now processing " << temp << "..." << endl;
	}

	return 0;
}