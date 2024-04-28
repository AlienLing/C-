#pragma once
#include"SavingAccount.h"
#include<iomanip>
#include<fstream>
class ManagerSavingAccount
{
	SavingAccount s[100];
	int num;
public:
	ManagerSavingAccount();
	void addSavingAccount();
	void printSavingAccount();
	void printByID(string id);
	void deleteByID(string id);
	void creditByID(string id,double c);
	void debitByID(string id,double d);
	void calculateInterestByID(string id);
};
ManagerSavingAccount::ManagerSavingAccount()
{
	num = 0;
}
void ManagerSavingAccount::addSavingAccount()
{
	s[num].input();
	num++;
}
void ManagerSavingAccount::printSavingAccount()
{
	for (int i = 0; i < num; i++)
	{
		cout << "The SavingAccount:" << endl;
		s[i].display();
	}
}
void ManagerSavingAccount::printByID(string id)
{
	for (int i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			s[i].display();
	}
}
void ManagerSavingAccount::deleteByID(string id)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			break;
	}
	if (i < num && s[i].getBalance() == 0)
	{
		for (int j = i; j < num; j++)
			s[j] = s[j + 1];
		num--;
	}
	else if (i >= num)
		cout << "没找到要删除的账户\n";
	else if(s[i].getBalance() != 0)
		cout << "余款没提取完\n";
}
void ManagerSavingAccount::creditByID(string id,double c)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			s[i].credit(c);
	}
}
void ManagerSavingAccount::debitByID(string id, double d)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			s[i].debit(d);
	}
}
void ManagerSavingAccount::calculateInterestByID(string id)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
		{
			cout << "利息为：" << s[i].calculateInterest()<<endl;
			s[i].credit(s[i].calculateInterest());
		}
	}
}