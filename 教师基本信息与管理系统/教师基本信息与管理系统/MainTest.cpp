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
	cout << "请选择登录系统：" << endl;
	cout << "1.教师系统		2.学生系统"<<endl;
	cin >> m;
	if (m==1)
	{
		cout << "请输入添加教师的人数:";
		cin >> n;
		for (int i = 0; i < n; i++)
			teachers.addTeacher();
		cout << "教师基本信息如下：" << endl;
		teachers.printTeacher();
		cout << "请输入待查院系名称：";
		cin >> dep;
		cout << dep << "教师基本信息如下：" << endl;
		teachers.printByDepartment(dep);
		cout << "请删除教师的职工号：";
		cin >> teaId;
		teachers.deleteByID(teaId);
		cout << "删除后所有教师的基本信息如下：" << endl;
		teachers.printTeacher();
	}
	else
	{
		cout << "请输入添加学生的人数:";
		cin >> n1;
		for (int i = 0; i < n1; i++)
			students.addStudent();
		cout << "学生基本信息如下：" << endl;
		students.printStudent();
		cout << "按分数从高到低显示学生信息：" << endl;
		students.printByScoure();
		cout << "请输入待查班级名称：";
		cin >> cls;
		cout << cls << "学生基本信息如下：" << endl;
		students.printByClasses(cls);
	}
	return 0;
}