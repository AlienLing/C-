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
		cout << "����ѧ�ţ�";
		cin >> Studentid;
		cout << "����������";
		cin >> name;
		cout << "�����Ա�";
		cin >> gender;
		cout << "�������䣺";
		cin >> age;
		cout << "���������";
		cin >> scoure;
		cout << "����༶��";
		cin >> classes;
	}
	void display()
	{
		cout << "  ѧ�ţ�" << Studentid << "\t";
		cout << "  ������" << name << "\t";
		cout << "  �Ա�" << gender << "\t";
		cout << "  ���䣺" << age << "\t";
		cout << "  ������" << scoure << "\t";
		cout << "  �༶��" << classes << "\t";
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