#include<iostream>
#include"teacher.h"
#include"managerteacher.h"
#include"student.h"
#include"managerstudent.h"
using namespace std;
int main()
{
	ManagerTeacher teachers;
	ManagerStudent students;
	int n,m,n1;
	string dep,cls;
	int teaId,stuId;
	cout << "��ѡ���¼ϵͳ��" << endl;
	cout << "1.��ʦϵͳ		2.ѧ��ϵͳ"<<endl;
	cin >> m;
	if (m==1)
	{
		cout << "��������ӽ�ʦ������:";
		cin >> n;
		for (int i = 0; i < n; i++)
			teachers.addTeacher();
		cout << "��ʦ������Ϣ���£�" << endl;
		teachers.printTeacher();
		cout << "���������Ժϵ���ƣ�";
		cin >> dep;
		cout << dep << "��ʦ������Ϣ���£�" << endl;
		teachers.printByDepartment(dep);
		cout << "��ɾ����ʦ��ְ���ţ�";
		cin >> teaId;
		teachers.deleteByID(teaId);
		cout << "ɾ�������н�ʦ�Ļ�����Ϣ���£�" << endl;
		teachers.printTeacher();
	}
	else
	{
		cout << "���������ѧ��������:";
		cin >> n1;
		for (int i = 0; i < n1; i++)
			students.addStudent();
		cout << "ѧ��������Ϣ���£�" << endl;
		students.printStudent();
		cout << "�������Ӹߵ�����ʾѧ����Ϣ��" << endl;
		students.printByScoure();
		cout << "���������༶���ƣ�";
		cin >> cls;
		cout << cls << "ѧ��������Ϣ���£�" << endl;
		students.printByClasses(cls);
	}
	return 0;
}