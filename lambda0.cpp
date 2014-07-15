#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long size_1 = 39L;
const long size_2 = 100 * size_1;
const long size_3 = 100 * size_2;

bool f3(int x) {return x % 3 == 0;}
bool f13(int x) {return x % 13 == 0;}

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::endl;

	std::vector<int> numbers(size_1);

	std::srand(std::time(0));
	std::generate(numbers.begin(), numbers.end(), std::rand);

	cout << "Sample size = " << size_1 << endl;
	int count_3 = std::count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3: " << count_3 << endl;
	int count_13 = std::count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13: " << count_13 << endl;

	numbers.resize(size_2);
	std::generate(numbers.begin(), numbers.end(), std::rand);

	cout << "Sample size = " << size_2 << endl;
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) : dv(d) {}
		bool operator()(int x) {return x % dv == 0;}
	};
	count_3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "Count of numbers divisible by 3: " << count_3 << endl;
	count_13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "Count of numbers divisible by 13: " << count_13 << endl;

	numbers.resize(size_3);
	std::generate(numbers.begin(), numbers.end(), std::rand);

	cout << "Sample size = " << size_3 << endl;
	count_3 = std::count_if(numbers.begin(), numbers.end(),
					[](int x) {return x % 3 == 0;});
	cout << "Count of numbers divisible by 3: " << count_3 << endl;
	count_13 = std::count_if(numbers.begin(), numbers.end(),
					[](int x) {return x % 13 == 0;});
	cout << "Count of numbers divisible by 13: " << count_13 << endl;

	return 0;
}