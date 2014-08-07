#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <occi.h>
#include <iomanip>
#include <cstdlib>

using namespace oracle::occi;
using namespace std;

class Student
{
private:
  Environment *env;
  Connection *conn;

  string user;
  string passwd;
  string db;

  struct StudentInfo
  {
    int stuID;
    string stuName;
    string stuDef;
  } stuInfo[4];

public:
  Student();
  virtual ~Student();

  void List();
};

#endif // STUDENT_H
