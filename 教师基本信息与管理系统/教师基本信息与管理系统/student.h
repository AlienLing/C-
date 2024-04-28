#pragma once
#include<string>
#include<iostream>
using namespace std;
class Student
{
	int Studentid;
	string name;
	string gender;
	int age;
	int scoure;
	string classes;
public:
	Student() {}
	Student(int Studentid, string name, string gender, int age, int scoure, string classes);
	int getstudentid();
	string getname();
	string getgender();
	int getscoure();
	string getclasses();
	int getage();
	void setteacherid(int teacherid) { this->Studentid = Studentid; }
	void setname(string name) { this->name = name; }
	void setgender(string gender) { this->gender = gender; }
	void settitle(int scoure) { this->scoure = scoure; }
	void setdepartment(string classes) { this->classes = classes; }
	void setage(int age) { this->age = age; }
	void input()
	{
		cout << "输入学号：";
		cin >> Studentid;
		cout << "输入姓名：";
		cin >> name;
		cout << "输入性别：";
		cin >> gender;
		cout << "输入年龄：";
		cin >> age;
		cout << "输入分数：";
		cin >> scoure;
		cout << "输入班级：";
		cin >> classes;
	}
	void display()
	{
		cout << "  学号：" << Studentid << "\t";
		cout << "  姓名：" << name << "\t";
		cout << "  性别：" << gender << "\t";
		cout << "  年龄：" << age << "\t";
		cout << "  分数：" << scoure << "\t";
		cout << "  班级：" << classes << "\t";
		cout << endl;
	}
};
Student::Student(int Studentid, string name, string gender, int age, int scoure, string classes)
{
	this->Studentid = Studentid;
	this->age = age;
	this->name = name;
	this->gender = gender;
	this->scoure = scoure;
	this->classes = classes;
}
int Student::getstudentid()
{
	return Studentid;
}
string Student::getname()
{
	return name;
}
string Student::getgender()
{
	return gender;
}
int Student::getscoure()
{
	return scoure;
}
string Student::getclasses()
{
	return classes;
}
int Student::getage()
{
	return age;
}