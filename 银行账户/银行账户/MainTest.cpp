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
	cout << "��ѡ���¼ϵͳ��" << endl;
	cout << "1.����˻�ϵͳ		2.֧Ʊ�˻�ϵͳ" << endl;
	cin >> m;
	if (m == 1)
	{
		int c, d;
		cout << "��������Ӵ���˻�������:";
		cin >> n;
		for (int i = 0; i < n; i++)
			SavingAccounts.addSavingAccount();
		cout << "����˻�������Ϣ���£�" << endl;
		SavingAccounts.printSavingAccount();
		cout << "����������˻�id��";
		cin >> id;
		SavingAccounts.printByID(id);
		cout << "����˻����:";
		cin >> c;
		SavingAccounts.creditByID(id, c);
		SavingAccounts.printByID(id);
		cout << "����˻�ȡ��:";
		cin >> d;
		SavingAccounts.debitByID(id, d);
		SavingAccounts.printByID(id);
		cout << "���н�Ϣ��" << endl;
		SavingAccounts.calculateInterestByID(id);
		SavingAccounts.printByID(id);
		cout << "��ɾ���˻���";
		cin >> cID;
		SavingAccounts.deleteByID(cID);
		cout << "ɾ���������˻��Ļ�����Ϣ���£�" << endl;
		SavingAccounts.printSavingAccount();
	}
	else
	{
		int c, d;
		cout << "���������֧Ʊ�˻�������:";
		cin >> n1;
		for (int i = 0; i < n1; i++)
			CheckingAccounts.addCheckingAccount();
		cout << "����˻�������Ϣ���£�" << endl;
		CheckingAccounts.printCheckingAccount();
		cout << "����������˻�id��";
		cin >> id;
		CheckingAccounts.printByID(id);
		cout << "����˻����:";
		cin >> c;
		CheckingAccounts.creditByID(id, c);
		CheckingAccounts.printByID(id);
		cout << "����˻�ȡ��:";
		cin >> d;
		CheckingAccounts.debitByID(id, d);
		CheckingAccounts.printByID(id);
		cout << "��ɾ���˻���";
		cin >> sID;
		CheckingAccounts.deleteByID(sID);
		cout << "ɾ���������˻��Ļ�����Ϣ���£�" << endl;
		CheckingAccounts.printCheckingAccount();
	}
	return 0;
}