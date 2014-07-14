#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Student
{
	int id;
	string name;
};

class m_sort
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
	
	map<Student, int, m_sort> map_student;

	Student student_info = {1, "tommy"};
	map_student.insert(make_pair(student_info, 90));
	student_info = {2, "john"};
	map_student.insert(make_pair(student_info, 88));
	student_info = {3, "kite"};
	map_student.insert(make_pair(student_info, 80));
	student_info = {4, "andrson"};
	map_student.insert(make_pair(student_info, 96));
	student_info = {5, "zibba"};
	map_student.insert(make_pair(student_info, 60));

	student_info = {1, "new student"};
	map_student.insert(make_pair(student_info, 100));

	for (auto it = map_student.begin(); it != map_student.end(); ++it)
	{
		cout << (it->first).id << " " << (it->first).name
		<< " score: " << it->second << endl;
	}

	return 0;
}