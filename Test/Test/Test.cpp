#include<iostream>
using namespace std;
int main()
{
	int i = 42;
	int* p = &i;
	decltype(*p)c = i;
}