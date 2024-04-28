#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"Date Time.h"
using namespace std;
int main()
{
	DateTime dt;
	dt.print12();
	dt.tick();
	dt.print24();
	return 0;
}