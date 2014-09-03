#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int> coll {2, 5, 4, 1, 6, 3};

    auto minpos = min_element(coll.begin(), coll.end());
    auto maxpos = max_element(coll.begin(), coll.end());

    cout << "min: " << *minpos << endl;
    cout << "max: " << *maxpos << endl;

    sort(coll.begin(), coll.end());
    for (auto it = coll.begin(); it != coll.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    auto pos = find(coll.begin(), coll.end(), 2);
    reverse(pos, coll.end());
    for (auto it = coll.begin(); it != coll.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

