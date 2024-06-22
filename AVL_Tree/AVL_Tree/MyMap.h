#pragma once

#include"RBTree.h"

namespace bit
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};

	void test_map1()
	{
		map<int, int> m;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		for (auto e : a)
		{
			m.insert(make_pair(e, e));
		}

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			//it->first += 100;
			it->second += 100;

			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
}
