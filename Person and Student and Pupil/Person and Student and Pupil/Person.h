#pragma once
#include<iostream>
using namespace std;
class Person
{
protected:
	string name;
	int age;
	char gender;
	string idCode;
public:
	Person(const string& na = "������", const int& ag = 18, const char& ge = 'M', const string id = "none")
	{
		name = na;
		age = ag;
		gender = ge;
		idCode = id;
	}
	void sayHello()
	{
		cout << "��Һã�����" << name << endl;
	}
	string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	char getgender()
	{
		return gender;
	}
	string gerid()
	{
		return idCode;
	}
};