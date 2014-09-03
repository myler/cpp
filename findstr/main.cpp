#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>

int main() {
    std::ifstream ifs("/home/myl/Documents/bak.txt");
    std::vector<std::string> vec((std::istream_iterator<std::string>(ifs)),
                                 std::istream_iterator<std::string>());
    auto pos = std::find(vec.begin(), vec.end(), "books.google.com");
    std::cout << *(pos - 1) << " " << *pos << std::endl;

    return 0;
}
