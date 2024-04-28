#pragma once
#include<string>
#include<iostream>
using namespace std;
class Teacher
{
	int Teacherid;
	string name;
	string gender;
	int age;
	string title;
	string department;
public:
	Teacher(){}
	Teacher(int Teacherid, string name, string gender, int age, string title, string department);
	int getteacherid();
	string getname();
	string getgender();
	string gettitle();
	string getdepartment();
	int getage();
	void setteacherid(int teacherid) { this->Teacherid = Teacherid; }
	void setname(string name) { this->name = name; }
	void setgender(string gender){ this->gender = gender; }
	void settitle(string title){ this->title = title; }
	void setdepartment(string department){ this->department = department; }
	void setage(int age){ this->age = age; }
	void input()
	{
		cout << "输入职工号：";
		cin >> Teacherid;
		cout << "输入姓名：";
		cin >> name;
		cout << "输入性别：";
		cin >> gender;
		cout << "输入年龄：";
		cin >> age;
		cout << "输入职称：";
		cin >> title;
		cout << "输入院系：";
		cin >> department;
	}
	void display()
	{
		cout << "职工号："<< Teacherid<<"\t";
		cout << "  姓名：" << name << "\t";
		cout << "  性别：" << gender << "\t";
		cout << "  年龄：" << age << "\t";
		cout << "  职称：" << title << "\t";
		cout << "  院系：" << department << "\t";
		cout << endl;
	}
};
Teacher::Teacher(int Teacherid, string name, string gender, int age, string title, string department)
{
	this->Teacherid = Teacherid;
	this->age = age;
	this->name = name;
	this->gender = gender;
	this->title = title;
	this->department = department;
}
int Teacher::getteacherid()
{
	return Teacherid;
}
string Teacher::getname()
{
	return name;
}
string Teacher::getgender()
{
	return gender;
}
string Teacher::gettitle()
{
	return title;
}
string Teacher::getdepartment()
{
	return department;
}
int Teacher::getage()
{
	return age;
}