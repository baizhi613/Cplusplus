#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>


class Manager :public Identity
{
public:

	Manager();

	Manager(string name,string pwd);

	virtual void openMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void initVector();

	bool checkRepeat(int id, int type);

	vector<Student> vStu;

	vector<Teacher> vTea;
};