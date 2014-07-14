 #include <iostream>
 #include <mysql/mysql.h>
 #include <string>

 using namespace std;

 int main(int argc, char const *argv[])
 {
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root", "815118", "test", 3306, NULL, 0);
    string sql = "insert into t1 (id, name) values (1, 'c++auto insert');";
    mysql_query(&mysql, sql.c_str());
    mysql_close(&mysql);

    return 0;
 }