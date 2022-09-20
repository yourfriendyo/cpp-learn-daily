#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <ctime>
#include "test.hpp"
#include "Hash.hpp"

using namespace std;

int main()
{
    // test_unordered_set();

    // test_op();

    // unordered_map<int, int> hash;
    // for (auto e : hash)
    //     cout << e.first << ":" << e.second << endl;
    // cout << endl << endl;;

    TestHash1();
    TestHash2();




    return 0;
}


void TestIndex()
{
    int key = 0;

    while (1)
    {
        set<int> s;

        int size = 0;

        cin >> key;

        int start = key % size;
        int index = start;

        for (int i = 0; i < 1000; i++)
        {
            s.insert(index);

            index = start + i * i;
            index %= size;
        }

        for (auto e : s)
        {
            cout << e << " ";
        }

    }

}