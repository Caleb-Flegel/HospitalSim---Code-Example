//Code for the time class's methods

//Importing string for formatting the output of times
#include <string>

//Importing the header
#include "../headers/Time.h"

//Constructor that will take given variables and put them into the time variables
Time::Time(int day, int hour, int minute): day(day), hour(hour), minute(minute) {}

//No args constructor that will set 0 to each time variabe
Time::Time(): day(0), hour(0), minute(0) {}

//Getters for the time variables
int Time::getDay() {return day;}
int Time::getHour() {return hour;}
int Time::getMinute() {return minute;}

//() functor that allows for easy adjusting of the time variables as needed, will be used after calculating times
void Time::operator() () {
    //While loop will add one to hour as long as there are 60 minutes to add
    while (minute >= 60) {
        hour++;
        minute -= 60;
    }

    //Another while loop will convert hours to days
    while (hour >= 24) {
        day++;
        hour -= 24;
    }
}

//Function that will convert a time to minutes
int Time::toMinutes(Time inpTime) {
    //Will add 24 hours for each day there is
    while (inpTime.day > 0) {
        inpTime.hour += 24;
        inpTime.day--;
    }

    //Another while loop will add to minutes while there is more than one hour
    while (inpTime.hour > 0) {
        inpTime.minute += 60; 
        inpTime.hour--; 
    }

    //Return the minutes of the temp time object
    return inpTime.getMinute();
}

//Function that advances time by a minute and adjusts the time if needed
void Time::advanceTime() {
    //add one to minutes
    minute++; 

    //Call the functor so the time can readjust
    //Calling and dereferencing this to get to the readjust functor
    (*this)(); 
}

// + Operator that will allow times to be added together
Time operator+ (Time& time1, Time& time2) {
    //Combine the times and return a new temp time object
    int newDay = time1.getDay() + time2.getDay();
    int newHour = time1.getHour() + time2.getHour();
    int newMin = time1.getMinute() + time2.getMinute();

    //Create a temp time and adjust it
    Time temp(newDay, newHour, newMin);
    temp();

    //Return the new time
    return temp;
}

// += operator makes it easier to call + operator
Time operator+= (Time& time1, Time& time2) {
    //Call and return the addition using the + operator
    return time1 + time2; 
}

// - operator allows time 2 to be subtracted from time 1
Time operator - (Time& time1, Time& time2) {
    //Combine the times and return a new temp time object
    int newDay = time1.getDay() - time2.getDay();
    int newHour = time1.getHour() - time2.getHour();
    int newMin = time1.getMinute() - time2.getMinute();

    //Make sure there aren't any negative minutes or hours
    //Check for minutes
    while (newMin < 0) {
        //Adding 60 minutes from the hours to get a positive minutes number
        newMin += 60;
        newHour --;
    }
    //Check for hours
    while (newHour < 0) {
        //Adding to hours from days to get a positive hours number
        newHour += 24;
        newDay --;
    }

    //Create a temp time and adjust it
    Time temp(newDay, newHour, newMin);
    temp();

    //Return the new time
    return temp;
}

// += operator makes it easier to call - operator
Time operator-= (Time& time1, Time& time2) {
    //Return the subtraction using the main operator method
    return time1 - time2; 
}

//<< Operator overload that will print the time 
std::ostream& operator<< (std::ostream& out, Time& tim) {
    //Add the time to the out stream
    out <<  tim.getDay() << " days, ";

    //If statement will add a 0 before the hour
    if (tim.getHour() < 10) {
        out << "0";
    }

    out << tim.getHour() << " hours, ";

    //If statement will add a 0 before minute if minute is a single digit
    if (tim.getMinute() < 10) {
        out << "0";
    }
    
    //Add the minute number
    out << tim.getMinute() << " minutes";

    //Return the completed time
    return out; 
}