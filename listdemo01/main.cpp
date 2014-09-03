#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    vector<int> coll1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> coll2;

    coll2.resize(coll1.size());
    copy(coll1.begin(), coll1.end(), coll2.begin());

    deque<int> coll3(coll1.size());
    copy(coll1.begin(), coll1.end(), coll3.begin());

//    void *p1 = (void*)&coll1;
//    void *p2 = (void*)&coll2;
//    void *p3 = (void*)&coll3;

//    char* ptrs[3];
//    ptrs[0] = (char*)p1;
//    ptrs[1] = (char*)p2;
//    ptrs[2] = (char*)p3;

//    for (auto i : (vector<int>)p1) {
//        cout << i << " ";
//    }
//    cout << endl;

    auto tpos = make_tuple(ref(coll1), ref(coll2), ref(coll3));
    for (auto i : get<0>(tpos)) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : get<1>(tpos)) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : get<2>(tpos)) {
        cout << i << " ";
    }
    cout << endl;

//    colls.push_back(coll1);
//    colls.push_back(coll2);
//    colls.push_back(coll3);

//    for (auto it = colls.begin(); it != colls.end(); ++it) {
//        for (auto i : *it) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }

//    for (auto it : coll1) {
//        cout << it << " ";
//    }
//    cout << endl;

//    for (auto it : coll2) {
//        cout << it << " ";
//    }
//    cout << endl;

//    for (auto it : coll3) {
//        cout << it << " ";
//    }
//    cout << endl;

    return 0;
}

