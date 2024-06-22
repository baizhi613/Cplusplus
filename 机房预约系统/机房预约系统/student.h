#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

class Student:public Identity
{
public:

	Student();

	Student(int Id,string Name,string Pwd);

	virtual void openMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	int m_Id;
};
