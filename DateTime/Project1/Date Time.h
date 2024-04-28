#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"Date.h"
#include"Time.h"
using namespace std;
class DateTime
{
	Date date;
	Time time;
public:
	DateTime();
	DateTime(Date d, Time t) :date(d), time(t) {};
	Date getDate()
	{
		return date;
	}
	Time getTime()
	{
		return time;
	}
	void print12()
	{
		date.printDate();
		time.print12();
		cout << endl;
	}
	void print24()
	{
		date.printDate();
		time.print24();
		cout << endl;
	}
	void tick()
	{
		time.tick();
		if (time.getHour() == 0 && time.getMinute() == 0 && time.getSecond() == 0)
			date.tick();
	}
	int getMonth()
	{
		return date.getMonth();
	}
	int getDay()
	{
		return date.getDay();
	}
	int getYear()
	{
		return date.getYear();
	}
	int getHour()
	{
		return time.getHour();
	}
	int getMinute()
	{
		return time.getMinute();
	}
	int getSecond()
	{
		return time.getSecond();
	}
};
DateTime::DateTime()
{
	Time t;
	Date d;
	time = t;
	date = d;
}
