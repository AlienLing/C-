#include<iostream>
using namespace std;
#include"Pupil.h"
int main()
{
	Pupil p("David", 20, 'M', "21382348137XXXXXXX", "202334234534", "南京工业大学", "大一", "会计01", 99, 77, 66);
	cout << p.getSchoolName()<<endl;
	cout << p.getgrade() << endl;
	cout << p.getclasses() << endl;
	cout << p.getsno() << endl;
	cout << p.getName() << endl;
	cout << p.getAge() << endl;
	cout << p.getgender() << endl;
	cout << p.gerid() << endl;
	cout << p.Sum() << endl;
	p.sayHello();
	p.testing();
}