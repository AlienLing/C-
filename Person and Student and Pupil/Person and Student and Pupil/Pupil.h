#pragma once
#include<iostream>
using namespace std;
#include"student.h"
class Pupil :public Student
{
protected:
	string grade;
	string classes;
	int chinese;
	int math;
	int english;
public:
	Pupil(const string& na = "无名氏", const int& ag = 18, const char& ge = 'M', const string id = "none", const string& sn = "000", const string& sName = "唐山师范学院",const string &grd="不知道", const string& cls ="不知道", const int& chi = 0, const int& mt = 0, const int& en = 0) :Student(na, ag, ge, id, sn, sName)
	{
		grade = grd;
		classes = cls;
		chinese = chi;
		math = mt;
		english = en;
	}
	int Sum()
	{
		return chinese + math + english;
	}
	string getgrade()
	{
		return grade;
	}
	string getclasses()
	{
		return classes;
	}
};
