#pragma once
#include"teacher.h"
#include<iomanip>
#include<fstream>
class ManagerTeacher
{
	Teacher s[100];
	int num;
public:
	ManagerTeacher();
	void addTeacher();
	void printTeacher();
	void printByDepartment(string dep);
	void deleteByID(int teacherid);
	void finout();
};
ManagerTeacher::ManagerTeacher()
{
	num = 0;
}
void ManagerTeacher::addTeacher()
{
	s[num].input();
	num++;
}
void ManagerTeacher::printTeacher()
{
	for (int i = 0; i < num; i++)
	{
		s[i].display();
	}
}
void ManagerTeacher::printByDepartment(string dep)
{
	for (int i = 0; i < num; i++)
	{
		if(s[i].getdepartment()==dep)
			s[i].display();
	}
}
void ManagerTeacher::deleteByID(int teacherid)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getteacherid() == teacherid)
			break;
	}
	if (i < num)
	{
		for (int j = i; j < num; j++)
			s[j] = s[j + 1];
		num--;
	}
	else
		cout << "没找到要删除的教师\n";
}
void ManagerTeacher::finout()
{
	const char* fName = "teacher.txt";
	Teacher tea;
	int teacherNum;
	int k;
	ifstream fin;
	ofstream fout;
	fin.open(fName, ios::binary);
	fin.read((char*)&tea, sizeof(tea));
}