#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->openMenu();

		Manager* man = (Manager*)manager;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = nullptr;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				return;
			}
		}
	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				return;
			}
		}
	}
	else if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;
}

int main()
{

	int select = 0;

	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ======================"
			<< endl;
		cout << endl << "������������" << endl;
		cout << "\t\t----------------------------------\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          1.ѧ������            |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          2.��ʦ                |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          3.����Ա              |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t|          0.�˳�                |\n";
		cout << "\t\t|                                |\n";
		cout << "\t\t----------------------------------\n";
		cout << "���������ѡ��:";

		cin >> select;

		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE,1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");

	return 0;
}