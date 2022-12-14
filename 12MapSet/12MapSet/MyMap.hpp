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

        typedef typename RBTree<K, pair<K, V>, MapKeyOfK>::iterator iterator;

        iterator begin() {
            return _t.begin();
        }

        iterator end() {
            return _t.end();
        }

        pair<iterator, bool> insert(const pair<K, V>& kv)
        {
            return _t.Insert(kv);
        }

        V& operator[](const K& key)
        {
            auto ret = _t.Insert(make_pair(key, V()));
            return ret.first->second;
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
        }

        map<int, int>::iterator it = m.begin();
        while (it != m.end())
        {
            cout << it->first << ":" << it->second << " ";
            ++it;
        }
        cout << endl;


        map<string, string> dict;

        dict.insert(make_pair("map", "地图"));
        dict.insert(make_pair("set", "位图"));
        dict.insert(make_pair("string", "字符串"));
        dict.insert(make_pair("sort", "排序"));

        map<string, string>::iterator dictIt = dict.begin();

        while (dictIt != dict.end())
        {
            cout << dictIt->first << ":" << dictIt->second << " ";
            ++dictIt;
        }
        cout << endl;


        cout << dict["map"] << endl;
        dict["map"] = "地图、map";
        cout << dict["map"] << endl;
    }
}