#include <iostream>

template <typename T1, typename T2>
inline auto gt(T1 a, T2 b) -> decltype(a + b);

int main(int argc, char const *argv[])
{
	using namespace std;

	int a = 10;
	double b = 9.9;

	auto c = gt(a, b);
	cout << c << endl;

	return 0;
}

template <typename T1, typename T2>
auto gt(T1 a, T2 b) -> decltype(a + b)
{
	return a + b;
}
