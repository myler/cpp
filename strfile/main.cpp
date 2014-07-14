#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
  ifstream fin;
  fin.open("../tobuy.txt");
  if (fin.is_open() == false)
    {
      cerr << "Can't open file. Bye.\n";
      exit(EXIT_FAILURE);
    }

  string item;
  int count = 0;

  do {
      getline(fin, item, ':');
      ++count;
      cout << count << ": " << item << endl;
    } while (fin);

  cout << "Done.\n";
  fin.close();

  return 0;
}
