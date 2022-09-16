#pragma once
#include <iostream>
#include "RBTree.hpp"

using namespace std;

namespace test
{
    template <class K, class V>
    class map
    {
    public:
        struct MapKeyOfK
        {
            const K& operator()(const pair<K, V>& kv) {
                return kv.first;
            }
        };

        bool insert(const pair<K, V>& kv)
        {
            return _t.Insert(kv);
        }

        void inorder() {
            _t.Inorder();
        }

    private:
        RBTree<K, pair<K, V>, MapKeyOfK> _t;
    };

    void test_map()
    {
        map<int, int> m;

        vector<int> v = { 1,2,3,4,5,6 };
        for (auto e : v)
        {
            m.insert(make_pair(e, e));
            m.inorder();
        }


    }

}