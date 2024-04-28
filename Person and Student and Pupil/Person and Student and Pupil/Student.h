#pragma once
#include<iostream>
#include"Person.h"
using namespace std;
class Student:public Person
{
protected:
	string sno;//学号
	string schoolName;//学校名称
public:
	Student(const string& na = "无名氏", const int& ag = 18, const char& ge = 'M', const string id = "none", const string& sn = "000", const string& sName = "唐山师范学院") :Person(na, ag, ge, id)
	{
		sno = sn;
		schoolName = sName;
	}
	void testing()
	{
		cout << getName() << "是" << schoolName << "的学生" << endl;
		cout << getName() << "正在考试中……\n";
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