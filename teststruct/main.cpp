#include <iostream>

using namespace std;

struct lab {
    int student_number;
    char *student_name;
};

int main()
{
    cout << "Hello World!" << endl;
    lab lab601;
    lab601 = {1, "CSW"};
    cout << lab601.student_number << " " << lab601.student_name << endl;
    return 0;
}

