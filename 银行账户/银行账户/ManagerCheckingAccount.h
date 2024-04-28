#pragma once
#include"CheckingAccount.h"
#include<iomanip>
#include<fstream>
class ManagerCheckingAccount
{
	CheckingAccount s[100];
	int num;
public:
	ManagerCheckingAccount();
	void addCheckingAccount();
	void printCheckingAccount();
	void printByID(string id);
	void deleteByID(string id);
	void creditByID(string id, double c);
	void debitByID(string id, double d);
};
ManagerCheckingAccount::ManagerCheckingAccount()
{
	num = 0;
}
void ManagerCheckingAccount::addCheckingAccount()
{
	s[num].input();
	num++;
}
void ManagerCheckingAccount::printCheckingAccount()
{
	for (int i = 0; i < num; i++)
	{
		cout << "The CheckingAccount:" << endl;
		s[i].display();
	}
}
void ManagerCheckingAccount::printByID(string id)
{
	for (int i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			s[i].display();
	}
}
void ManagerCheckingAccount::deleteByID(string id)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			break;
	}
	if (i < num&&s[i].getBalance()==0)
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
void ManagerCheckingAccount::creditByID(string id, double c)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			s[i].credit(c);
	}
}
void ManagerCheckingAccount::debitByID(string id, double d)
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s[i].getID() == id)
			s[i].debit(d);
	}
}