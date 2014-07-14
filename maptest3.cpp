#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	
	map<char, int> m_map;

	m_map['a'] = 10;
	m_map['b'] = 20;
	m_map['c'] = 30;
	m_map['d'] = 40;
	m_map['e'] = 50;
	m_map['f'] = 60;
	m_map['g'] = 70;

	m_map.insert(make_pair('h', 80));

	cout << "Initial m_map contains:\n";
	for (auto it = m_map.begin(); it != m_map.end(); ++it)
	{
		cout << it->first << " --- " << it->second << endl;
	}

	auto it = m_map.find('b');
	m_map.erase(it);
	m_map.erase('c');
	it = m_map.find('e');
	auto iit = m_map.find('g');
	m_map.erase(it, ++iit);

	cout << "Now m_map contains:\n";
	for (auto it = m_map.begin(); it != m_map.end(); ++it)
	{
		cout << it->first << " --- " << it->second << endl;
	}

	return 0;
}