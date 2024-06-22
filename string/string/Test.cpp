#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string a;
	//getline(cin, a);
	//cout << "返回字符串的长度："<<a.size() << endl;
	//cout << "返回字符串的长度："<<a.length() << endl;
	//cout << "返回已分配存储空间的大小："<<a.capacity() << endl;
	//a.resize(10);
	//cout << "返回resize后字符串的长度：" << a.length() << endl;
	//a.reserve(20);
	//cout << "返回reserve后已分配存储空间的大小：" << a.capacity() << endl;
	//string b = "hello world";
	//cout <<"第二个字符："<< b[1] << endl;
	//cout << "第三个字符："<< b.at(2) << endl;
	//cout <<"返回字符串最后一个字符的引用："<< b.back() << endl;
	//cout << "返回字符串第一个字符的引用：" << b.front() << endl;
	//b += " vscode";
	//cout << b << endl;
	//b.append(" clion");
	//cout << b << endl;
	//b.push_back('a');
	//cout << b << endl;
	//b.assign("hello qt");
	//cout << "为字符串重新指定内容："<<b << endl;
	//b.insert(1,"h");
	//cout << b << endl;
	//const char* c = "abcd";
	//b.insert(2, c);
	//cout << b << endl;
	//b.erase(2, 4);
	//cout << b << endl;
	//b.replace(2, 5, "abcde");
	//cout << b << endl;
	//string d("cccc");
	//b.swap(d);
	//cout << b << endl;
	//b.pop_back();
	//cout << b << endl;
	//string n{ "1234" };
	//cout << n << endl;
	string a("abc");
	string b(a);
	cout << b;
	a.push_back('d');
	cout << a;
	return 0;
}