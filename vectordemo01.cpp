#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool write_file(const char *fp);
bool read_file(const char *fp);

int main(int argc, char const *argv[])
{
	const char *fp = "vector-data.txt";

	if (!write_file(fp))
	{
		cout << "write_file error." << endl;
	}
	if (!read_file(fp))
	{
		cout << "read_file error." << endl;
	}

	return 0;
}

bool write_file(const char *fp)
{
	ofstream fout;
	fout.open(fp);
	if (!fout.is_open())
	{
		cout << "Can't open " << fp << ". Bye." << endl;
		return false;
	}

	const int LIM = 10;
	vector<string> v1;
	for (int i = 0; i < LIM; ++i)
	{
		string temp = " -------------->";
		v1.push_back(temp);
	}

	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		fout << *i << endl;
	}

	fout.close();
	return true;
}

bool read_file(const char *fp)
{
	ifstream fin;
	fin.open(fp);
	if (!fin.is_open())
	{
		cout << "Can't open " << fp << ". Bye." << endl;
		return false;
	}

	vector<string> v2;
	while(fin) {
		string temp;
	    getline(fin, temp);
	    v2.insert(v2.end(), temp);
	}

	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		cout << *i << endl;
	}
	cout << v2.size() <<endl;
	cout << v2.capacity() << endl;

	fin.close();
	return true;
}
