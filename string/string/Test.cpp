#include<iostream>
#include<string>
using namespace std;
int main()
{
	//string a;
	//getline(cin, a);
	//cout << "�����ַ����ĳ��ȣ�"<<a.size() << endl;
	//cout << "�����ַ����ĳ��ȣ�"<<a.length() << endl;
	//cout << "�����ѷ���洢�ռ�Ĵ�С��"<<a.capacity() << endl;
	//a.resize(10);
	//cout << "����resize���ַ����ĳ��ȣ�" << a.length() << endl;
	//a.reserve(20);
	//cout << "����reserve���ѷ���洢�ռ�Ĵ�С��" << a.capacity() << endl;
	//string b = "hello world";
	//cout <<"�ڶ����ַ���"<< b[1] << endl;
	//cout << "�������ַ���"<< b.at(2) << endl;
	//cout <<"�����ַ������һ���ַ������ã�"<< b.back() << endl;
	//cout << "�����ַ�����һ���ַ������ã�" << b.front() << endl;
	//b += " vscode";
	//cout << b << endl;
	//b.append(" clion");
	//cout << b << endl;
	//b.push_back('a');
	//cout << b << endl;
	//b.assign("hello qt");
	//cout << "Ϊ�ַ�������ָ�����ݣ�"<<b << endl;
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