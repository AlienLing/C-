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
		cout << "����ְ���ţ�";
		cin >> Teacherid;
		cout << "����������";
		cin >> name;
		cout << "�����Ա�";
		cin >> gender;
		cout << "�������䣺";
		cin >> age;
		cout << "����ְ�ƣ�";
		cin >> title;
		cout << "����Ժϵ��";
		cin >> department;
	}
	void display()
	{
		cout << "ְ���ţ�"<< Teacherid<<"\t";
		cout << "  ������" << name << "\t";
		cout << "  �Ա�" << gender << "\t";
		cout << "  ���䣺" << age << "\t";
		cout << "  ְ�ƣ�" << title << "\t";
		cout << "  Ժϵ��" << department << "\t";
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