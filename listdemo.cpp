#include <iostream>
#include <list>

using namespace std;

list<int> g_list_1;
list<int> g_list_2;

void InitList();
void ShowList(const list<int> &m_list);
void equality_test();
void assign_test();
void reverse_test(list<int> &m_list);
void sort_test();
void merge_test();

int 
main(int argc, char const *argv[])
{
	InitList();
	ShowList(g_list_1);
	ShowList(g_list_2);
	equality_test();
	assign_test();
	reverse_test(g_list_1);
	sort_test();
	merge_test();

	return 0;
}

void InitList()
{
	g_list_1.push_back(1);
	g_list_1.push_back(2);
	g_list_1.push_back(3);

	g_list_2.push_front(6);
	g_list_2.push_front(5);
	g_list_2.push_front(4);
}

void ShowList(const list<int> &m_list)
{
	cout << "list size: " << m_list.size() << endl;
	cout << "list max size: " << m_list.max_size() << endl;

 	cout << "list content: "; 
	for (auto i = m_list.begin(); i != m_list.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;

	cout << "list front: " << m_list.front()
	<< " and list end: " << m_list.back() << endl << endl;
}

void equality_test()
{
	g_list_1 = g_list_2;
	ShowList(g_list_1);
	ShowList(g_list_2);
}

void assign_test()
{
	list<int> listTemp(5, 1);
	ShowList(listTemp);

	listTemp.assign(4, 3);
	ShowList(listTemp);

	listTemp.assign(++g_list_1.begin(), g_list_1.end());
	ShowList(listTemp);
}

void reverse_test(list<int> &m_list)
{
	ShowList(m_list);
	m_list.reverse();
	ShowList(m_list);
}

void sort_test()
{
	list<int> listTemp;
	listTemp.push_back(9);
	listTemp.push_back(3);
	listTemp.push_back(5);
	listTemp.push_back(1);
	listTemp.push_back(4);
	listTemp.push_back(7);
	listTemp.push_back(6);
	listTemp.push_back(4);
	listTemp.push_back(2);
	listTemp.push_back(9);
	listTemp.push_back(8);
	listTemp.push_back(0);

	ShowList(listTemp);
	listTemp.sort();
	ShowList(listTemp);
	listTemp.sort(greater<int>());
	ShowList(listTemp);
	listTemp.unique();
	ShowList(listTemp);
}

void merge_test()
{
	ShowList(g_list_1);
	ShowList(g_list_2);
	g_list_1.merge(g_list_2, greater<int>());
	ShowList(g_list_1);
}