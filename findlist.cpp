#include <iostream>
#include <list>
#include <string>

using namespace std;

void InitList(list<string> &m_list);
void SearchList(list<string> &m_list, string key);

int main(int argc, char const *argv[])
{
	list<string> oracle_info;
	InitList(oracle_info);
	SearchList(oracle_info, "res2011q1");

	return 0;
}

void InitList(list<string> &m_list)
{
	m_list.push_back("Oracle Achieves Record TPC-C Benchmark Result on 2 Processor System. http://www.oracle.com/us/corporate/press/1853058");
	m_list.push_back("Oracle Delivers World Record x86 Performance on Industry Standard Java Middleware and Transactional Database Benchmarks. http://www.oracle.com/us/corporate/press/1570421");
	m_list.push_back("Oracle Achieves World Record Two Processor Result with SPECjEnterprise2010 Benchmark. http://www.oracle.com/us/corporate/press/1584316");
	m_list.push_back("Oracle Delivers World Record x86 Performance on Industry Standard Java Middleware and Transactional Database Benchmarks. http://www.oracle.com/us/corporate/press/1570421");
	m_list.push_back("Oracle Weblogic Server Standard Edition Release 10.3.4 on Cisco UCS B440 M1 Blade Server. http://www.spec.org/jEnterprise2010/results/res2011q1/jEnterprise2010-20110223-00019.txt");
	m_list.push_back("Oracle Weblogic Server Standard Edition Release 10.3.4 on Dell PowerEdge R910. http://www.spec.org/jEnterprise2010/results/res2011q2/jEnterprise2010-20110323-00021.txt");
	m_list.push_back("Oracle Linux Delivers Top CPU Benchmark Results on Sun Blades. http://blogs.oracle.com/linux/entry/oracle_linux_delivers_top_cpu_benchmark_results_on_sun_blades");
}

void SearchList(list<string> &m_list, string key)
{
	for (auto i = m_list.begin(); i != m_list.end(); ++i)
	{
		string temp = *i;
		if (temp.find(key) != temp.npos)
		{
			size_t pos = temp.find("http");
			string value = temp.substr(pos);
			cout << value << endl;
			break;
		} else {
			if (i == --m_list.end())
				cout << "not found" << endl;
		}
	}
}