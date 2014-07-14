#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Student
{
	int id;
	string name;
} stu1, stu2, stu3;

class setCmp
{
public:
	bool operator()(const Student &stu1, const Student &stu2) const
	{
		if (stu1.id == stu2.id)
			return stu1.name.compare(stu2.name) < 0;
		return stu1.id < stu2.id;
	}
};

int main(int argc, char const *argv[])
{
	
	set<Student, setCmp> student_info;

	stu1 = {1, "zhang san"};
	stu2 = {2, "li si"};
	stu3 = {3, "wang wu"};

	student_info.insert(stu1);
	student_info.insert(stu2);
	student_info.insert(stu3);

	cout << "Student size: ";
	cout << student_info.size() << endl;
	for (auto it = student_info.begin(); it != student_info.end(); ++it)
	{
		cout << "id: " << it->id << " name: " << it->name << endl;
	}

	return 0;
}