#pragma once

#ifndef PROJECTCLOCKTIME_H
#define PROJECTCLOCKTIME_H	

#include<iostream>

//Class for clock project
class ProjectClockTime {

private:
	void printTime24();
	void printTime12();

	int hours24;
	int minutes;
	int seconds;
public:
	ProjectClockTime(); //Default constructor
	void setTime(int hour, int min, int sec);
	void AddHour();
	void AddMinute();
	void AddSecond();
	void DisplayClock();
	int getHour();
	int getMinute();
	int getSecond();
	void setHour(int hour);
	void setMinute(int min);
	void setSecond(int sec);
	void displayMenu();
	bool ReadUserInput();
	void ClearScreen();
};

#endif