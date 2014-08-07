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

void Student::List()
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
          cout << endl << setw(3) << left <<"ID"
                  << setw(6) << left << "NAME"
                     << setw(8) << left << "DEFINITION"
                        << endl;
          cout << "===================" << endl;
          while (rs->next())
            {
              cout << setw(3) << left << rs->getInt(1)
                      << setw(6) << left << rs->getString(2)
                         << setw(8) << left << rs->getString(3)
                            << endl;
            }
          cout << "===================" << endl;
          cout << endl;
          stmt->closeResultSet(rs);
        }
      conn->terminateStatement(stmt);
    }
}
