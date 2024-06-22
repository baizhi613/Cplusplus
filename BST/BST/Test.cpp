#include"BinarySearchTree .h"
#include<iostream>
using namespace std;
int main()
{
	BSTree<int> t;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();

	t.Erase(8);

	t.InOrder();
	return 0;
}