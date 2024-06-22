#pragma once

#include"RBTree.h"

namespace bit
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, const K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const K& key)
		{
			return _t.Insert(key);
		}

	private:
		RBTree<K, const K, SetKeyOfT> _t;
	};

	void test_set1()
	{
		set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		for (auto e : a)
		{
			s.insert(e);
		}

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			//if(*it % 2 == 0)
			//	*it += 100;

			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}
