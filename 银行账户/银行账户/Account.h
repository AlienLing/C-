#pragma once
#include<iostream>
#include"Date.h"
using namespace std;
class Account
{
	string ID;
	Date openDay;
	double balance;//”‡∂Ó
public:
	Account(){}
	Account(string,double);
	void credit(double);
	bool debit(double);
	double getBalance()const;
	void outopenDay()const;
	string getID();
	void display()
	{
		cout << "account ID :" << ID << "\t\t";
		cout << "open day:";
		outopenDay();
		cout<< "balance:" << balance << endl;
	}
	void input()
	{
		cout << "create account id:";
		cin >> ID;
		outopenDay();
		cout << endl;
		cout << "input balance:";
		cin >> balance;
	}
};
Account::Account(string id,double b):ID(id)
{
	if(b>=0)
		balance = b;
	else
	{
		balance = 0;
		cout << "Input an invalid number!\n";
	}
}
void Account::credit(double c)
{
	balance += c;
}
bool Account::debit(double d)
{
	if (d > balance)
	{
		cout << "Debit amount exceeded account balance."<<endl;
		return false;
	}
	else
	{
		balance -= d;
		return true;
	}
}
double Account::getBalance()const
{
	return balance;
}
void Account::outopenDay()const
{
	openDay.printDate();
}
string Account::getID()
{
	return ID;
}