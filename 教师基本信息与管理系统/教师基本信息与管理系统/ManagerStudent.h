#pragma once
#include"student.h"
class ManagerStudent
{
	Student s[100];
	int num;
public:
	ManagerStudent();
	void addStudent();
	void printStudent();
	void printByClasses(string cls);
	void printByScoure();
};
ManagerStudent::ManagerStudent()
{
	num = 0;
}
void ManagerStudent::addStudent()
{
	s[num].input();
	num++;
}
void ManagerStudent::printStudent()
{
	for (int i = 0; i < num; i++)
	{
		s[i].display();
	}
}
void ManagerStudent::printByClasses(string cls)
{
	for (int i = 0; i < num; i++)
	{
		if (s[i].getclasses() == cls)
			s[i].display();
	}
}
void ManagerStudent::printByScoure()
{
	Student s1;
	for (int i = 0; i < num-1; i++)
	{
		if (s[i].getscoure() > s[i + 1].getscoure())
		{
			s1 = s[i];
			s[i] = s[i + 1];
			s[i + 1] = s1;
		}
	}
	for (int i = 0; i < num; i++)
	{
		s[i].display();
	}
}
