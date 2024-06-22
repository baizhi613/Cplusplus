#pragma once
#include<iostream>
using namespace std;
enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		,_col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//叔叔存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//叔叔不存在或存在且为黑
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//叔叔不存在或存在且为黑
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
		void RotateL(Node * parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			subR->_left = parent;
			Node* ppnode = parent->_parent;
			parent->_parent = subR;

			if (parent == _root)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = subR;
				}
				else
				{
					ppnode->_right = subR;
				}
				subR->_parent = ppnode;
			}
		}

		void RotateR(Node * parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			subL->_right = parent;

			Node* ppnode = parent->_parent;
			parent->_parent = subL;

			if (parent == _root)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = subL;
				}
				else
				{
					ppnode->_right = subL;
				}
				subL->_parent = ppnode;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_kv.first << endl;
			_InOrder(root->_right);
		}

		void InOrder()
		{
			_InOrder(_root);
		}

		bool Check(Node* cur, int blackNum, int refBlackNum)
		{
			if (cur == nullptr)
			{
				if (refBlackNum != blackNum)
				{
					cout << "黑色节点的数量不相等" << endl;
					return false;
				}

				//cout << blackNum << endl;
				return true;
			}

			if (cur->_col == RED && cur->_parent->_col == RED)
			{
				cout << cur->_kv.first << "存在连续的红色节点" << endl;
				return false;
			}

			if (cur->_col == BLACK)
				++blackNum;

			return Check(cur->_left, blackNum, refBlackNum)
				&& Check(cur->_right, blackNum, refBlackNum);
		}

		bool IsBalance()
		{
			if (_root && _root->_col == RED)
				return false;

			int refBlackNum = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_col == BLACK)
					refBlackNum++;

				cur = cur->_left;
			}

			return Check(_root, 0, refBlackNum);
		}

		size_t Size()
		{
			return _Size(_root);
		}

		size_t _Size(Node* root)
		{
			if (root == NULL)
				return 0;

			return _Size(root->_left)
				+ _Size(root->_right) + 1;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < key)
				{
					cur = cur->_right;
				}
				else if (cur->_kv.first > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return NULL;
		}

		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);

			return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}

		int Height()
		{
			return _Height(_root);
		}

		int GetRotateSize()
		{
			return rotateSize;
		}

private:
	Node* _root=nullptr;
	int rotateSize = 0;
};

void TestRBTree1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));

		// 1、先看是插入谁导致出现的问题
		// 2、打条件断点，画出插入前的树
		// 3、单步跟踪，对比图一一分析细节原因
		//cout << e << "->" << t.IsBalance() << endl;
	}

	t.InOrder();
	cout << t.IsBalance() << endl;
}

void TestRBTree2()
{
	const int N = 1000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
		//cout << v.back() << endl;
	}

	size_t begin2 = clock();
	RBTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	size_t end2 = clock();

	cout << "Insert:" << end2 - begin2 << endl;

	cout << t.IsBalance() << endl;

	cout << "Height:" << t.Height() << endl;
	cout << "Size:" << t.Size() << endl;

	size_t begin1 = clock();
	// 确定在的值
	for (auto e : v)
	{
		t.Find(e);
	}

	// 随机值
	for (size_t i = 0; i < N; i++)
	{
		t.Find((rand() + i));
	}

	size_t end1 = clock();

	cout << "Find:" << end1 - begin1 << endl;
}