#pragma once
#include<iostream>
#include"Account.h"
using namespace std;
class SavingAccount :public Account
{
	static double rate;
public:
	SavingAccount(){}
	SavingAccount(string, double);
	double calculateInterest()const;//ÀûÏ¢
	static double getRate();
};
double SavingAccount::rate = 0.003;
SavingAccount::SavingAccount(string id, double b):Account(id,b)
{
}
double SavingAccount::calculateInterest()const
{
	return rate * getBalance();
}
double SavingAccount::getRate()
{
	return rate;
}