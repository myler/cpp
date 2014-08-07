#include <student.h>

int
main(void)
{
  Student *stu = new Student();
  stu->List();
  delete stu;

  return 0;
}
