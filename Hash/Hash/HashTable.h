#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
namespace open_address
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY; // 标记
	};

	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	// 特化
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto e : s)
			{
				hash += e;
				hash *= 131;
			}

			return hash;
		}
	};

	//struct HashFuncString
	//{
	//	size_t operator()(const string& s)
	//	{
	//		// "abcd"
	//		// "bcad"
	//		// "aadd"
	//		size_t hash = 0;
	//		for (auto e : s)
	//		{
	//			hash += e;
	//			hash *= 131;
	//		}
	//
	//		return hash;
	//	}
	//};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable(size_t size = 10)
		{
			_tables.resize(size);
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash hs;
			// 线性探测
			size_t hashi = hs(key) % _tables.size();
			while (_tables[hashi]._state != EMPTY)
			{
				if (key == _tables[hashi]._kv.first
					&& _tables[hashi]._state == EXIST)
				{
					return &_tables[hashi];
				}

				++hashi;
				hashi %= _tables.size();
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			// 扩容的问题  10:50继续
			//if ((double)_n / (double)_tables.size() >= 0.7)
			if (_n * 10 / _tables.size() >= 7)
			{
				//size_t newSize = _tables.size() * 2;
				//vector<HashData> newTables(newSize);
				//// 遍历旧表，映射到新表
				////....
				//_tables.swap(newTables);

				HashTable<K, V, Hash> newHT(_tables.size() * 2);
				// 遍历旧表，插入到新表
				for (auto& e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				_tables.swap(newHT._tables);
			}

			Hash hs;
			// 线性探测
			size_t hashi = hs(kv.first) % _tables.size();
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _tables.size();
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				_n--;
				ret->_state = DELETE;
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;  // 实际存储的数据个数
	};

	void TestHT1()
	{
		int a[] = { 1,4,24,34,7,44,17,37 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		for (auto e : a)
		{
			auto ret = ht.Find(e);
			if (ret)
			{
				cout << ret->_kv.first << ":E" << endl;
			}
			else
			{
				cout << ret->_kv.first << ":D" << endl;
			}
		}
		cout << endl;

		ht.Erase(34);
		ht.Erase(4);

		for (auto e : a)
		{
			auto ret = ht.Find(e);
			if (ret)
			{
				cout << ret->_kv.first << ":E" << endl;
			}
			else
			{
				cout << e << ":D" << endl;
			}
		}
		cout << endl;
	}

	struct Date
	{
		int _year;
		int _month;
		int _day;
	};

	struct HashFuncDate
	{
		// 2024/6/3
		// 2024/3/6
		size_t operator()(const Date& d)
		{
			size_t hash = 0;
			hash += d._year;
			hash *= 131;

			hash += d._month;
			hash *= 131;

			hash += d._day;
			hash *= 131;

			return hash;
		}
	};

	struct Person
	{
		string _name;
		string _id;   // 身份证号码
		string _tel;
		int _age;
		string _class;

		string _address;  // 
		//...
	};

	// 11：57继续
	struct HashFuncPerson
	{
		// 2024/6/3
		// 2024/3/6
		size_t operator()(const Person& p)
		{
			size_t hash = 0;
			for (auto e : p._id)
			{
				hash += e;
				hash *= 131;
			}

			return hash;
		}
	};

	void TestHT2()
	{
		HashTable<string, string> dict;
		dict.Insert(make_pair("sort", "排序"));
		dict.Insert(make_pair("string", "字符串"));

		//HashFuncString hfs;
		//cout << hfs("bacd") << endl;
		//cout << hfs("abcd") << endl;
		//cout << hfs("aadd") << endl;

		HashTable<Date, string, HashFuncDate> DateHash;
	}
}

namespace hash_bucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
		{
			_tables.resize(10, nullptr);
			_n = 0;
		}

		bool Insert(const pair<K, V>& kv)
		{
			size_t hashi = kv.first % _tables.size();
			Node* newnode = new Node(kv);

			// 头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
		}
	private:
		//vector<list<pair<K, V>>> _tables;
		vector<Node*> _tables; // 指针数组
		size_t _n;
	};
}
