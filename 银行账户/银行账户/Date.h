#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;
class Date
{
	int y;
	int m;
	int d;
public:
	Date();
	void printDate()const;
};
Date::Date()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	y = st.wYear;
	m = st.wMonth;
	d = st.wDay;
}//ֱ������ı������
void Date::printDate()const
{
	cout << setfill('0') << setw(4) << y << '-' << setw(2) << m << '-' << setw(2) << d <<"\t";
}