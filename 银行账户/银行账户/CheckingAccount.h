#pragma once
#include<iostream>
#include"Account.h"
using namespace std;
class CheckingAccount :public Account
{
	static double fee;
public:
	CheckingAccount(){}
	CheckingAccount(string, double);
	void credit(double);
	bool debit(double);
	static double getfee();
};
double CheckingAccount::fee = 0.002;
CheckingAccount::CheckingAccount(string id, double b) :Account(id,b) 
{
}
void CheckingAccount::credit(double c)
{
	Account::credit( c - fee*c);
}
bool CheckingAccount::debit(double d)
{
	if (Account::debit(d) == true)
	{
		Account::debit(d+ fee*d);
		return true;
	}
}
double CheckingAccount::getfee()
{
	return fee;
}