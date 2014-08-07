#include "student.h"

Student::Student()
{
  user = "myl";
  passwd = "815118";
  db = "127.0.0.1:1521/orcl";

  env = Environment::createEnvironment(Environment::DEFAULT);

  try
  {
    conn = env->createConnection(user, passwd, db);
  }
  catch (SQLException &e)
  {
    cout << e.getMessage();
    exit(EXIT_FAILURE);
  }
}

Student::~Student()
{
  env->terminateConnection(conn);
  Environment::terminateEnvironment(env);
}

Student::StudentInfo Student::List()
{
  Statement *stmt = NULL;
  ResultSet *rs = NULL;

  string sql = "select * from sql_test_table";

  try
  {
    stmt = conn->createStatement(sql);
  }
  catch (SQLException &e)
  {
    cout << e.getMessage();
  }

  if (stmt)
    {
      try
      {
        rs = stmt->executeQuery();
      }
      catch (SQLException &e)
      {
        cout << e.getMessage();
      }
      if (rs)
        {
          while (rs->next())
            {
              int i = 0;
              stuInfo[i].stuID = rs->getInt(1);
              stuInfo[i].stuName = rs->getString(2);
              stuInfo[i].stuDef = rs->getString(3);
              i++;
            }
          stmt->closeResultSet(rs);
        }
      conn->terminateStatement(stmt);
    }
  return stuInfo;
}
