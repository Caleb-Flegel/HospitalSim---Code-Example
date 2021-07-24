//Header file that will store the time class, which will help with datermining and calculating times

#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
private:
    //Day hour and minute variables that will store the time
    int day;
    int hour;
    int minute;

public:
    //Constructor that will take given variables and put them into the time variables
    Time(int day, int hour, int minute);

    //No args constructor that will set 0 to each time variabe
    Time();

    //Getters for the time variables
    int getDay();
    int getHour();
    int getMinute(); 

    //() functor that allows for easy adjusting of the time variables as needed, will be used after calculating times
    void operator() ();

    //Function that will convert a time to minutes
    int toMinutes(Time inpTime);     

    //Function that advances time by a minute and adjusts the time if needed
    void advanceTime();
};

// + Operator that will allow times to be added together
Time operator+ (Time& time1, Time& time2); 

// += operator makes it easier to call + operator
Time operator+= (Time& time1, Time& time2);

// - operator allows time 2 to be subtracted from time 1
Time operator- (Time& time1, Time& time2); 

// -= operator makes it easier to call - operator
Time operator-= (Time& time1, Time& time2);

//<< Operator overload that will print the time 
std::ostream& operator<< (std::ostream& out, Time& tim);

#endif