#include <iostream>
#include <mysql++/mysql++.h>

int main(int argc, char const *argv[])
{
	using namespace std;

	mysqlpp::Connection conn(false);
	if (conn.connect("test", "localhost", "root", "815118"))
	{
		mysqlpp::Query query = conn.query("select * from t1");
		if (mysqlpp::StoreQueryResult res = query.store())
		{
			cout << "We have: " << endl;
			cout << '\t' << "id" << '\t' << "name" << endl;
			for (size_t i = 0; i < res.num_rows(); ++i)
			{
				cout << '\t' << res[i][0] << '\t' << res[i][1] << endl;
			}
		} else {
			cerr << "Failed to get item list: " << query.error() << endl;
			return 1;
		}
		return 0;
	} else {
		cerr << "DB connection failed: " << conn.error() << endl;
		return 1;
	}
}