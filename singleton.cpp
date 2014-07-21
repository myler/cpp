#include <iostream>
#include <string>
#include <memory>
#include "boost/thread/thread.hpp"
#include "boost/thread/mutex.hpp"

using namespace std;

boost::mutex sg_mutex;

template<typename T>
class Singleton
{
private:
	Singleton()
	{
	cout << "Singleton getInstance" << endl;
	}

	static auto_ptr<T> _instance;
public:
	static auto_ptr<T> getInstance()
	{
		sg_mutex.lock();
		if (!_instance.get())
		{
			auto_ptr<T> temp(new T);
			_instance = temp;
		}

		return _instance;
	}
};

class Student
{
private:
	string stu_name;
	int stu_age;
public:
	Student(const string name = "Andrew", const int age = 25)
	 : stu_name(name), stu_age(age)
	{
		cout << "Constructor..." << endl;
	}
	void print_info() const;
};

void Student::print_info() const
{
	cout << "Name: " << stu_name << " age: " << stu_age << endl;
}

//auto_ptr<Student> Singleton<Student>::_instance;

void getSingletonInstance()
{
	auto_ptr<Student> mySingleton(Singleton<Student>::getInstance());
	mySingleton->print_info();

	sg_mutex.unlock();
}

int main(int argc, char const *argv[])
{
	boost::thread thread_A(getSingletonInstance);
	boost::thread thread_B(getSingletonInstance);
	boost::thread thread_C(getSingletonInstance);
	boost::thread thread_D(getSingletonInstance);

	thread_A.join();
	thread_B.join();
	thread_C.join();
	thread_D.join();

	return 0;
}