//#include<string>
//#include <iostream>
//using namespace std;
//
//class Person {
//public:
//	string _name = "Peter";
//	int _age = 18;
//public:
//	void Print() {
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//};
//
//class Student :public Person {
//public:
//	void fun() {
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _stuid;
//};
//
//class Teacher :public Person {
//protected:
//	int _teaid;
//};
//
//int main() {
//	Student s;
//	s.Print();
//
//	s.fun();
//
//}

//#include<iostream>
//using namespace std;
//
//int main() {
	//int a = 0;
	//int* p;//����ָ�����
	//p = &a;//ָ��ָ��a����¼a�ĵ�ַ
	//cout << p << endl;//a�ĵ�ַ��000000558AFCF904
	//cout << &a << endl;//����һ��������һ��

	//cout << *p << endl;//*Ϊ�����ã�*pΪָ��ָ���ڴ��е�ֵ

	//cout << sizeof(p) << endl;
	//cout << sizeof(float*) << endl;
	//cout << sizeof(double*) << endl;
	//cout << sizeof(char*) << endl;//ָ����ռ�ڴ�ռ�Ϊ8���ֽڣ�64λ��

	//int b = 10;
	//const int* p1 = &b;
	////*p1 = 20;����ָ��ָ������ݲ���ͨ��ָ���޸�
	//p1 = &a;//�������޸�ָ���ָ��

	//int c = 20;
	//int* const p2 = &c;
	//*p2 = 30;
	////p2 = &a;

	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* p = arr;//������Ϊ�����׵�ַ
	//cout << *p << endl;//���1
	//cout << *(p+1) << endl;//���2��*���ȼ�����++������+
//
//}

//#include<iostream>
//using namespace std;
//{
////
////class Person {
////public:
////	Person(){}
////	Person(int n,int m):m_A(n),m_B(m){}
////	int m_A;
////	int m_B;
////	Person operator+(const Person& other)
////	{
////		Person temp;
////		temp.m_A = this->m_A + other.m_A;
////		temp.m_B = this->m_B + other.m_B;
////		return temp;
////	}
////};
////int main() {
////	Person p1(10,20), p2(10,20);
////	Person p3 = p1 + p2;
////	cout << p3.m_A << endl;
////	cout << p3.m_B << endl;
//
//	class Person {
//
//	};
//
//}

//#include<iostream>
//using namespace std;
//class Person {
//private:
//	int n;
//public:
//
//	friend ostream& operator<<(ostream& os, const Person& obj)//�������������
//	{
//		os << "n:" << obj.n;
//		return os;
//	}
//
//	Person& operator++()//����ǰ��++
//	{
//		++n;
//		return *this;
//	}
//
//	Person operator++(int)//���غ���++
//	{
//		Person temp = *this;
//		n++;
//		return temp;
//	}
//
//	Person(int n) {
//		val = new int(n);
//	}
//	int* val;
//	~Person()
//	{
//		if (val != NULL)
//		{
//			delete val;
//			val = NULL;
//		}
//	}
//
//	Person& operator=(Person& obj)
//	{
//		if (val != NULL)
//		{
//			delete val;
//			val = NULL;
//		}
//		val = new int(*obj.val);
//		return *this;
//	}
//};
//int main() {
//	Person p(10);
//	cout << p << endl;
//	cout << p++ << endl;
//	cout << p << endl;
//	Person p1(10);
//	Person p2(20);
//	p1 = p2;
//	cout << p1 << endl;
//	cout << p2<< endl;
//}

//#include<iostream>
//using namespace std;
//template<typename T>
//
//void myswap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}

//void swapInt(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void swapDouble(int& a, int& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}

//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//myswap(a,b);
//	myswap<int>(a, b);
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}
//
//#include <graphics.h> // ���� EasyX ͷ�ļ�
//int main() {
//	// ��ʼ��ͼ�ν���
//	initgraph(640, 480); // ����һ�� 640x480 �Ĵ���
//
//	// �ڴ����л���һ��Բ��
//	setcolor(YELLOW); // ���û�ͼ��ɫΪ��ɫ
//	fillellipse(320, 240, 100, 100); // �ڴ����л���һ���뾶Ϊ 100 ��Բ��
//
//	// �ȴ��û��رմ���
//	getchar(); // �ȴ��û����������
//
//	// �ر�ͼ�ν���
//	closegraph(); // �ر�ͼ�ν���
//
//	return 0;
//}
//
//EasyX ��һ�������õ�ͼ�ν���⣬�ṩ��һϵ�л�ͼ�������¼������������ڴ���ͼ���û����棨GUI��Ӧ�ó��������� EasyX �г��õĺ������书�ܣ�
//
//1. * *��ʼ���͹ر� * *��
//- `initgraph()`����ʼ��ͼ�ν��棬�������ڲ�����ͼ��ģʽ��
//- `closegraph()`���ر�ͼ�ν��棬�ͷ������Դ��
//
//2. * *��ͼ���� * *��
//- `line()`������ֱ�ߡ�
//- `circle()`������Բ�Ρ�
//- `ellipse()`��������Բ��
//- `rectangle()`�����ƾ��Ρ�
//- `roundrect()`������Բ�Ǿ��Ρ�
//- `arc()`������Բ����
//- `pie()`���������Ρ�
//- `polygon()`�����ƶ���Ρ�
//- `floodfill()`�����������
//- `putpixel()`�����Ƶ������ص㡣
//
//3. * *��ɫ����ʽ * *��
//- `setcolor()`�����û�ͼ��ɫ��
//- `setfillcolor()`�����������ɫ��
//- `setbkcolor()`�����ñ�����ɫ��
//- `setlinestyle()`������������ʽ��
//- `settextstyle()`�������ı���ʽ��
//
//4. * *�ı����� * *��
//- `outtextxy()`����ָ��λ�û����ı���
//- `outtext()`���ڵ�ǰ���λ�û����ı���
//- `outtextxy()`����ָ��λ�û����ı���
//- `settextcolor()`�������ı���ɫ��
//- `setbkmode()`�������ı�����ģʽ��
//
//5. * *���̺�����¼� * *��
//- `kbhit()`���������Ƿ������롣
//- `getch()`����ȡ�������롣
//- `mousemsg()`����ȡ�����Ϣ��
//- `getmouse()`����ȡ���״̬��
//- `GetMouseMsg()`����ȡ�����Ϣ���꣩��
//
//6. * *�������� * *��
//- `delay()`���ӳ�ִ��һ��ʱ�䡣
//- `rand()`�������������
//- `srand()`��������������ӡ�
//- `timeGetTime()`����ȡ��ǰʱ�䡣
//
#define _CRT_SECURE_NO_WARININGS 1
#include<iostream>
#include<string>
#include<iterator>
#include"string.h"
#include <vector>
//string�ڵײ�ʵ���ǣ�basic_stringģ����ı���
//typedef basic_string<char, char_traits, allocator>string;
using namespace std;
//int main()
//{
	////�����ַ���
	//string st1;
	//string st2 = "Hello";
	//string st3(5, 'A');

	////�ַ�����ֵ
	//string str;
	//string str0 ("World");// string(const char* s)
	//str = "Hello";//��������
	//string str4(str0);//��������
	//str.assign("World");
	////cout << str;

	////�ַ���ƴ��
	//string str1 = "Hello";
	//string str2 = "World";
	//string str3 = str1 + " " + str2;
	////cout << str3;
	//str1.append(str2);

	//int len = str2.size();
	//cout << len << endl;
	//cout << str2.length() << endl;
	//cout << str2.capacity() << endl;
	//cout << str3.capacity() << endl;
	//str1.clear();//�����Ч�ַ�
	//str1.resize(10,'a');//���ַ����ַ�������ӵ�10�����λ����a���
	//str2.resize(15); //���λ����/0���
	//str3.resize(5);//��С
	//
	//str3.reserve(20); //���ı���ЧԪ�ظ�������reserve�Ĳ���С��string�ĵײ�ռ��ܴ�Сʱ��reserver����ı�������С��
	//cout << str3.capacity()<< endl;//���ܱ�Ϊ20�����


	//string str = "Hello";
	//for (int i = 0; i < str.size(); i++)//�±��at����
	//{
	//	char ch = str[i];
	//	//char ch = str.at(i);
	//	cout << ch ;
	//}
	//cout << endl;
	//for (char ch1 : str)//��Χfor
	//{
	//	cout << ch1 ;
	//}
	//cout << endl;
	//for (auto it = str.begin(); it != str.end(); it++)//������
	//{
	//	char ch2 = *it;
	//	cout << ch2;
	//}
	//cout << endl;
	//string::iterator it = str.begin();
	//while (it != str.end())
	//{
	//	cout << *it;
	//	it++;
	//}
	//cout << endl;
	//for (auto it = str.rbegin(); it != str.rend(); ++it) {
	//	char ch3 = *it;//���������
	//	cout << ch3;
	//}

	//int val = stoi("1234");//�ַ���ת����
	//string str = to_string(3.14);//����ת�ַ���
//}
//#include<vector>
//#include<iterator>
//int main()
//{
//	//����vector
//	vector<int> vec1;
//	vector<int> vec2 { 1,2,3,4,5 };
//	vector<int> vec3(4);//�����ĸ��ռ�
//	vector<int> vec4(5, 3);//5��ֵΪ3
//	vector<int> vec5(vec2);
//
//	//����vector
//	for (vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	for (auto n : vec2)
//	{
//		cout << n << " " ;
//	}
//	cout << endl;
//	vec2.push_back(6);
//	vec2.push_back(7);
//	vec2.pop_back();
//	for (auto n : vec2)
//	{
//		cout << n << " ";
//	}
//	cout << endl;
//	vec1.insert(vec1.begin(),3,5);
//	for (auto n : vec1)
//	{
//		cout << n << " ";
//	}
//	vec1.swap(vec2);
//}
//ȷ����������
//��������Ԫ�ظ����ﵽ��ǰ����ʱ����ҪΪ�������������ڴ�ռ䡣ͨ�����������ǵ�ǰ������������
//�������ڴ棺
//���������һ���µ��ڴ�ռ䣬��СΪ�����������ڴ洢���ݺ��Ԫ�ء�
//����Ԫ�أ�
//�����Ὣԭ����Ԫ�ظ��Ƶ��µ��ڴ�ռ��С�
//�ͷž��ڴ棺
//�������ͷ�ԭ�����ڴ�ռ䣬�Ա㽫����������Ŀ�ġ�
//����������Ϣ��
//������������ڲ���������Ϣ���Է�ӳ�µ�������
//
//#include<vector>
//#include<iterator>
//int main()
//{
//	vector<int> v1 = { 1,2,3,4,5,6 };
//	cout << v1.size() << endl;
//	int left = 0;
//	int right = v1.size();
//	unsigned int a = -10;
//
//	return 0;
//}
//vector<vector<int>> generate(int numRows) {
//	vector<vector<int>> tran(numRows);
//	for (int i = 0; i < numRows; i++)
//	{
//		tran[i].resize(i + 1);
//		tran[i][0] = tran[i][i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			tran[i][j] = tran[i - 1][j] + tran[i - 1][j - 1];
//		}
//	}
//	return tran;
//}
//int main()
//{
//	vector<vector<int>> a=generate(5);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[100],b[100]={0}, n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j >= 0; j--)
//		{
//			if (a[j] < a[i])
//			{
//				b[i]++;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout<<b[i]<<" ";
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main() {
//	int a[21][21] = { 0 },n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		a[i][1] = a[i][i] = 1;
//		for (int j = 2; j < i; j++)
//		{
//			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
