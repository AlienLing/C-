#include<iostream>
using namespace std;
#include"SavingAccount.h"
#include"CheckingAccount.h"
#include"ManagerCheckingAccount.h"
#include"ManagerSavingAccount.h"
int main()
{
	string id,cID,sID;
	int m,n,n1;
	ManagerCheckingAccount CheckingAccounts;
	ManagerSavingAccount SavingAccounts;
	cout << "Before any accounts ctreated:\n";
	cout << "The rate of the savingAccount is:" << SavingAccount::getRate()<<endl;
	cout << "The fee of the checkingAccount is:" << CheckingAccount::getfee() << endl;
	cout << "请选择登录系统：" << endl;
	cout << "1.存款账户系统		2.支票账户系统" << endl;
	cin >> m;
	if (m == 1)
	{
		int c, d;
		cout << "请输入添加存款账户的人数:";
		cin >> n;
		for (int i = 0; i < n; i++)
			SavingAccounts.addSavingAccount();
		cout << "存款账户基本信息如下：" << endl;
		SavingAccounts.printSavingAccount();
		cout << "请输入待查账户id：";
		cin >> id;
		SavingAccounts.printByID(id);
		cout << "向此账户存款:";
		cin >> c;
		SavingAccounts.creditByID(id, c);
		SavingAccounts.printByID(id);
		cout << "向此账户取款:";
		cin >> d;
		SavingAccounts.debitByID(id, d);
		SavingAccounts.printByID(id);
		cout << "进行结息：" << endl;
		SavingAccounts.calculateInterestByID(id);
		SavingAccounts.printByID(id);
		cout << "请删除账户：";
		cin >> cID;
		SavingAccounts.deleteByID(cID);
		cout << "删除后所有账户的基本信息如下：" << endl;
		SavingAccounts.printSavingAccount();
	}
	else
	{
		int c, d;
		cout << "请输入添加支票账户的人数:";
		cin >> n1;
		for (int i = 0; i < n1; i++)
			CheckingAccounts.addCheckingAccount();
		cout << "存款账户基本信息如下：" << endl;
		CheckingAccounts.printCheckingAccount();
		cout << "请输入待查账户id：";
		cin >> id;
		CheckingAccounts.printByID(id);
		cout << "向此账户存款:";
		cin >> c;
		CheckingAccounts.creditByID(id, c);
		CheckingAccounts.printByID(id);
		cout << "向此账户取款:";
		cin >> d;
		CheckingAccounts.debitByID(id, d);
		CheckingAccounts.printByID(id);
		cout << "请删除账户：";
		cin >> sID;
		CheckingAccounts.deleteByID(sID);
		cout << "删除后所有账户的基本信息如下：" << endl;
		CheckingAccounts.printCheckingAccount();
	}
	return 0;
}