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
	//int* p;//定义指针变量
	//p = &a;//指针指向a，记录a的地址
	//cout << p << endl;//a的地址：000000558AFCF904
	//cout << &a << endl;//与上一行输出结果一致

	//cout << *p << endl;//*为解引用，*p为指针指向内存中的值

	//cout << sizeof(p) << endl;
	//cout << sizeof(float*) << endl;
	//cout << sizeof(double*) << endl;
	//cout << sizeof(char*) << endl;//指针所占内存空间为8个字节（64位）

	//int b = 10;
	//const int* p1 = &b;
	////*p1 = 20;常量指针指向的内容不能通过指针修改
	//p1 = &a;//但可以修改指针的指向

	//int c = 20;
	//int* const p2 = &c;
	//*p2 = 30;
	////p2 = &a;

	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* p = arr;//数组名为数组首地址
	//cout << *p << endl;//输出1
	//cout << *(p+1) << endl;//输出2，*优先级高于++，低于+
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
//	friend ostream& operator<<(ostream& os, const Person& obj)//重载左移运算符
//	{
//		os << "n:" << obj.n;
//		return os;
//	}
//
//	Person& operator++()//重载前置++
//	{
//		++n;
//		return *this;
//	}
//
//	Person operator++(int)//重载后置++
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
//#include <graphics.h> // 包含 EasyX 头文件
//int main() {
//	// 初始化图形界面
//	initgraph(640, 480); // 创建一个 640x480 的窗口
//
//	// 在窗口中绘制一个圆形
//	setcolor(YELLOW); // 设置绘图颜色为黄色
//	fillellipse(320, 240, 100, 100); // 在窗口中绘制一个半径为 100 的圆形
//
//	// 等待用户关闭窗口
//	getchar(); // 等待用户按下任意键
//
//	// 关闭图形界面
//	closegraph(); // 关闭图形界面
//
//	return 0;
//}
//
//EasyX 是一个简单易用的图形界面库，提供了一系列绘图函数和事件处理函数，用于创建图形用户界面（GUI）应用程序。以下是 EasyX 中常用的函数及其功能：
//
//1. * *初始化和关闭 * *：
//- `initgraph()`：初始化图形界面，创建窗口并设置图形模式。
//- `closegraph()`：关闭图形界面，释放相关资源。
//
//2. * *绘图函数 * *：
//- `line()`：绘制直线。
//- `circle()`：绘制圆形。
//- `ellipse()`：绘制椭圆。
//- `rectangle()`：绘制矩形。
//- `roundrect()`：绘制圆角矩形。
//- `arc()`：绘制圆弧。
//- `pie()`：绘制扇形。
//- `polygon()`：绘制多边形。
//- `floodfill()`：填充封闭区域。
//- `putpixel()`：绘制单个像素点。
//
//3. * *颜色和样式 * *：
//- `setcolor()`：设置绘图颜色。
//- `setfillcolor()`：设置填充颜色。
//- `setbkcolor()`：设置背景颜色。
//- `setlinestyle()`：设置线条样式。
//- `settextstyle()`：设置文本样式。
//
//4. * *文本绘制 * *：
//- `outtextxy()`：在指定位置绘制文本。
//- `outtext()`：在当前光标位置绘制文本。
//- `outtextxy()`：在指定位置绘制文本。
//- `settextcolor()`：设置文本颜色。
//- `setbkmode()`：设置文本背景模式。
//
//5. * *键盘和鼠标事件 * *：
//- `kbhit()`：检测键盘是否有输入。
//- `getch()`：获取键盘输入。
//- `mousemsg()`：获取鼠标消息。
//- `getmouse()`：获取鼠标状态。
//- `GetMouseMsg()`：获取鼠标消息（宏）。
//
//6. * *其他功能 * *：
//- `delay()`：延迟执行一段时间。
//- `rand()`：生成随机数。
//- `srand()`：设置随机数种子。
//- `timeGetTime()`：获取当前时间。
//
#define _CRT_SECURE_NO_WARININGS 1
#include<iostream>
#include<string>
#include<iterator>
#include"string.h"
#include <vector>
//string在底层实际是：basic_string模板类的别名
//typedef basic_string<char, char_traits, allocator>string;
using namespace std;
//int main()
//{
	////创建字符串
	//string st1;
	//string st2 = "Hello";
	//string st3(5, 'A');

	////字符串赋值
	//string str;
	//string str0 ("World");// string(const char* s)
	//str = "Hello";//拷贝构造
	//string str4(str0);//拷贝构造
	//str.assign("World");
	////cout << str;

	////字符串拼接
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
	//str1.clear();//清空有效字符
	//str1.resize(10,'a');//将字符串字符个数添加到10，多出位置用a填充
	//str2.resize(15); //多出位置用/0填充
	//str3.resize(5);//缩小
	//
	//str3.reserve(20); //不改变有效元素个数，当reserve的参数小于string的底层空间总大小时，reserver不会改变容量大小。
	//cout << str3.capacity()<< endl;//可能变为20或更大


	//string str = "Hello";
	//for (int i = 0; i < str.size(); i++)//下标或at访问
	//{
	//	char ch = str[i];
	//	//char ch = str.at(i);
	//	cout << ch ;
	//}
	//cout << endl;
	//for (char ch1 : str)//范围for
	//{
	//	cout << ch1 ;
	//}
	//cout << endl;
	//for (auto it = str.begin(); it != str.end(); it++)//迭代器
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
	//	char ch3 = *it;//反向迭代器
	//	cout << ch3;
	//}

	//int val = stoi("1234");//字符串转整形
	//string str = to_string(3.14);//整形转字符串
//}
//#include<vector>
//#include<iterator>
//int main()
//{
//	//创建vector
//	vector<int> vec1;
//	vector<int> vec2 { 1,2,3,4,5 };
//	vector<int> vec3(4);//开辟四个空间
//	vector<int> vec4(5, 3);//5个值为3
//	vector<int> vec5(vec2);
//
//	//遍历vector
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
//确定新容量：
//当向量的元素个数达到当前容量时，需要为向量分配更大的内存空间。通常，新容量是当前容量的两倍。
//分配新内存：
//向量会分配一块新的内存空间，大小为新容量，用于存储扩容后的元素。
//复制元素：
//向量会将原来的元素复制到新的内存空间中。
//释放旧内存：
//向量会释放原来的内存空间，以便将其用于其他目的。
//更新容量信息：
//向量会更新其内部的容量信息，以反映新的容量。
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
