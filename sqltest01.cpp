#include <iostream>
#include <occi.h>

using namespace std;
using namespace oracle::occi;

int
main(void)
{
	Environment *env = Environment::createEnvironment(Environment::DEFAULT);
	cout << "success" << endl;

	string name = "myl";
	string passwd = "815118";
	string db = "127.0.0.1:1521/orcl";

	try
	{
		Connection *conn = env->createConnection(name, passwd, db);
		cout << "conn success" << endl;
		env->terminateConnection(conn);
	}
	catch (SQLException e)
	{
		cout << e.what() << endl;
		return -1;
	}
	Environment::terminateEnvironment(env);
	cout << "end!" << endl;

	return 0;
}