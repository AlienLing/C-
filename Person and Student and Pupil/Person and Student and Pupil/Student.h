#pragma once
#include<iostream>
#include"Person.h"
using namespace std;
class Student:public Person
{
protected:
	string sno;//ѧ��
	string schoolName;//ѧУ����
public:
	Student(const string& na = "������", const int& ag = 18, const char& ge = 'M', const string id = "none", const string& sn = "000", const string& sName = "��ɽʦ��ѧԺ") :Person(na, ag, ge, id)
	{
		sno = sn;
		schoolName = sName;
	}
	void testing()
	{
		cout << getName() << "��" << schoolName << "��ѧ��" << endl;
		cout << getName() << "���ڿ����С���\n";
	}
	string getSchoolName()
	{
		return schoolName;
	}
	string getsno()
	{
		return sno;
	}
};