
#include"projectclocktime.h"
#include<windows.h>
#include<conio.h>
#include<iostream>

using namespace std;



int main() {

    ProjectClockTime clock;
    clock.setTime(1, 12, 34);

    do {
        clock.ClearScreen();
        clock.DisplayClock();
        clock.displayMenu();
    } while (clock.ReadUserInput());


    return 0;
}