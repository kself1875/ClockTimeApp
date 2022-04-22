
#include"projectclocktime.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//Default constructor
ProjectClockTime::ProjectClockTime() {
    hours24 = 0;
    minutes = 0;
    seconds = 0;
}


void ProjectClockTime::setTime(int hour, int min, int sec) {
    if (hour >= 0 && hour <= 23) { //we use if here to check the correctness of input value
        hours24 = hour;
    }
    if (min >= 0 && min <= 59) { //we use if here to check the correctness of minutes
        minutes = min;
    }
    if (sec >= 0 && sec <= 59) { //we use if here to check the correctness of seconds
        seconds = sec;
    }
}

void ProjectClockTime::setHour(int hour) {

    if (hour >= 0 && hour <= 23) { //we use if here to check the correctness of input value
        hours24 = hour;
    }
}

void ProjectClockTime::setMinute(int min) {

    if (min >= 0 && min <= 59) { //we use if here to check the correctness of minutes
        minutes = min;
    }
}

void ProjectClockTime::setSecond(int sec) {

    if (sec >= 0 && sec <= 59) { //we use if here to check the correctness of seconds
        seconds = sec;
    }
}

int ProjectClockTime::getHour() {
    return hours24;
}

int ProjectClockTime::getMinute() {
    return minutes;
}

int ProjectClockTime::getSecond() {
    return seconds;
}


void ProjectClockTime::AddHour() {

    hours24 = (hours24 + 1) % 24;

}


void ProjectClockTime::AddMinute() {
    ++minutes;
    hours24 = (hours24 + minutes / 60) % 24; //This will take care of the hours if we get mins larger than 59
    minutes %= 60; //this will keep the value between 0 and 59
}

void ProjectClockTime::AddSecond() {
    ++seconds;
    minutes += seconds / 60;
    hours24 += minutes / 60;
    seconds %= 60;
    minutes %= 60;
    hours24 %= 24;
}

void ProjectClockTime::printTime24() {
    cout << setw(2) << setfill('0');
    cout << hours24;
    cout << ":";
    cout << setw(2) << setfill('0');
    cout << minutes;
    cout << ":";
    cout << setw(2) << setfill('0');
    cout << seconds;
}


void ProjectClockTime::printTime12() {
    int hours12 = hours24 % 12;
    if (hours12 == 0)
        hours12 = 12; //use this if statement since in 12h format hours cannot be 0

    cout << setw(2) << setfill('0');
    cout << hours12;
    cout << ":";
    cout << setw(2) << setfill('0');
    cout << minutes;
    cout << ":";
    cout << setw(2) << setfill('0');
    cout << seconds;
    if (hours24 < 12) {
        cout << "AM";
    }
    else {
        cout << "PM";
    }
}


void ProjectClockTime::DisplayClock() {
    cout << "*****************************";
    cout << "          ";
    cout << "*****************************";
    cout << endl;
    cout << "*       12-Hour Clock       *";
    cout << "          ";
    cout << "*       24-Hour Clock       *";
    cout << endl;
    cout << "*         ";
    printTime12();
    cout << "        *";
    cout << "          ";
    cout << "*          ";
    printTime24();
    cout << "         *";
    cout << endl;
    cout << "*****************************";
    cout << "          ";
    cout << "*****************************";
    cout << endl;
}


void ProjectClockTime::displayMenu() {

    cout << "*****************************" << endl;
    cout << "*  1 - Add One Hour         *" << endl;
    cout << "*  2 - Add One Minute       *" << endl;
    cout << "*  3 - Add One Second       *" << endl;
    cout << "*  4 - Exit Program         *" << endl;
    cout << "*****************************" << endl;
}


void ProjectClockTime::ClearScreen() {
    for (int i = 0; i < 40; i++)
        cout << endl;
}

bool ProjectClockTime::ReadUserInput() {
    bool shouldContinue = true;              // this function will read user input and decide whether program should continue
    int choice;
    cin >> choice;
    switch (choice) {                        // use switch statement to react to the users choice
    case 1:
        AddHour();
        break;

    case 2:
        AddMinute();
        break;

    case 3:
        AddSecond();
        break;

    case 4:
        shouldContinue = false;
        break;

    default:
        break;
    }
    return shouldContinue;
}