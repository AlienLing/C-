#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;
class Time
{
	int h;
	int m;
	int s;
public:
	Time();
	Time(int h,int m,int s);
	void setTime(int h, int m, int s);
	void print24();
	void print12();
	void tick();
	int getHour()
	{
		return h;
	}
	int getMinute()
	{
		return m;
	}
	int getSecond()
	{
		return s;
	}
};
Time::Time()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	h = st.wHour;
	m = st.wMinute;
	s = st.wSecond;
}
Time::Time(int h, int m, int s)
{
	this->h = h;
	this->m = m;
	this->s = s;
}
void Time::setTime(int h, int m, int s)
{
	this->h = h;
	this->m = m;
	this->s = s;
}
void Time::print24()
{
	if(h<=12)
		cout << setfill('0') << setw(2) << h << ':' << setw(2)<<m << ':' << setw(2)<<s<<" am";
	else
		cout << setfill('0') << setw(2) << h << ':' << setw(2) << m << ':' << setw(2) << s << " pm";
}
void Time::tick()
{
	s++;
	if (s >= 60)
	{
		m++;
		s = 0;
		if (m >= 60)
		{
			h++;
			m = 0;
		}
	}
}
void Time::print12()
{
	if(h<=12)
		cout  << setfill('0') << setw(2) << h << ':' << setw(2) << m << ':' << setw(2) << s << " am" ;
	else
		cout  << setfill('0') << setw(2) << h-12 << ':' << setw(2) << m << ':' << setw(2) << s <<" pm";
}