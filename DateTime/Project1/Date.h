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
	int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int runmonthDays[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
public:
	Date();
	Date(int y, int m, int d);
	void setDate(int y, int m, int d);
	void printDate();
	void tick();
	bool isLeapYear(int);
	int getMonth()
	{
		return y;
	}
	int getDay()
	{
		return m;
	}
	int getYear()
	{
		return d;
	}
};
Date::Date()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	y = st.wYear;
	m = st.wMonth;
	d = st.wDay;
}
Date::Date(int y, int m, int d)
{
	this->y = y;
	this->m = m;
	this->d = d;
}
void Date::setDate(int y1, int m1, int d1)
{
	if (y1 > 1900 && y1 < 9999)
		y = y1;
	if (m1 >= 1 && m1<= 12)
		m = m1;
	if (m == 2 && isLeapYear(y))
	{
		if (d1 >= 1 && d1 <= 29)
			d = d1;
	}
	if (d1 >= 1 && d1 <= monthDays[m])
	{
		d = d1;
	}
}//直接输入改变的日期
void Date::printDate()
{
	cout << setfill('0') << setw(4) << y << '-' << setw(2) << m << '-' << setw(2) << d <<' ';
}
bool Date::isLeapYear(int n)
{
	if (n % 4 == 0 || n % 100 == 0 && n % 400 != 0)
		return true;
	return false;
}//判断是否为闰年
void Date::tick()
{
	d++;
	if (isLeapYear(y) == 0)
	{
		if ( d> monthDays[m])
		{
			m++;
			if (m > 12)
				y++;
		}
	}
	else
	{
		if (d > runmonthDays[m])
		{
			m++;
			if (m > 12)
				y++;
		}
	}
}//日期后一天