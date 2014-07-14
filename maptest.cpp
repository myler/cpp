#include <iostream>
#include <map>

int main(int argc, char const *argv[])
{
	std::map<char, int> first;
	first['a'] = 10;
	first['b'] = 20;
	first['c'] = 30;
	first['d'] = 40;
	first['e'] = 50;

	std::map<char, int> second(first.begin(), first.end());
	std::map<char, int> third(second);

	second.insert(std::pair<char, int>('f', 60));

	for (auto ret = second.begin(); ret != second.end(); ++ret)
	{
		std::cout << (*ret).first << ": " << (*ret).second << std::endl;
	}

	return 0;
}