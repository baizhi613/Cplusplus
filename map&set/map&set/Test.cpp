#include<iostream>
using namespace std;
#include<set>
#include<map>

void test_set1()
{
	set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(3);
	s.insert(4);

	auto start = s.lower_bound(3);//>=
	cout << *start << endl;
	auto finish = s.upper_bound(5);//>
	cout << *finish << endl;
	s.erase(start, finish);//[)

	set<int>::iterator it= s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator pos = s.find(5);
	while (pos != s.end())
	{
		cout << "ÕÒµ½ÁË" << endl;
		it++;
	}
	cout << endl;
}

void test_set2()
{
	multiset<int> s;//¿ÉÖØ¸´
	s.insert(1);
	s.insert(1);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map1()
{
	map<string,string> dict;
	dict.insert(pair<string, string>("sort", "ÅÅĞò"));

	pair<string, string> kv = { "string","×Ö·û´®" };
	dict.insert(kv);

	dict.insert({ "apple","Æ»¹û" });//c++11

	dict.insert(make_pair("sort", "ÅÅĞò"));//c++98

	map<string, string>::iterator it = dict.begin();

	while (it != dict.end())
	{
		cout << it->first << it->second << endl;
		it++;
	}
}

int main()
{
	//test_set1();
	//test_set2();
	test_map1();
	return 0;
}