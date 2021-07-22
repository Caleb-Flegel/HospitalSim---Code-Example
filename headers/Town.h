//Class header file for the town, which will contain the hospital and all of the residents

#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <map> 
#include <string>
#include <fstream>

//Import the hospital class
#include "Hospital.h"

class Town
{
private:
    //Will have a map for the list of citizens
    //Will be static so it can be accessed by a getter
    static std::map <std::string, std::string> residentList; 

    //Has one hospital object
    Hospital mainHospital; 

    //Time variables that keep track of the time
    //These will be static, so they can be pulled by sub classes
    static int second;
    static int minute;
    static int hour;
    static int day;

    //Function that gets converts the time to a string to be used in cout statements
    //Needs to be static to be accessed by other classes
    static void setTime();

    //String used to store the string version of the time, will be used in other classes, so it will be static
    static std::string time;

    //Variable that will store the chance per second that a resident will need to visit the emergency room
    int emergencyChnce; 

public:
    //Consructor, which will take the number of desired doctors and nurses and pass it to the hospital class as well as fill the resident list map
    //sickChance will be a chance to get sick per day, will be converted to seconds in constructor 
    Town(int docNum, int nurNum, int sickChance): emergencyChnce(sickChance * 24 * 60 * 60) {mainHospital.addProviders(docNum, nurNum);
                                                                                             pullCitizens();}

    //Function that pulls the names of the town's citizens
    void pullCitizens();  

    //getter that returns the string form of time
    //Will be static so the time can be used in other, non-child classes
    static std::string getTime();

    //Getters for the induvidual time variables
    int getDay() {return day;}
    int getHour() {return hour;}
    int getMinute() {return minute;}
    int getSecond() {return second;}
        
    //Setter function that advances the time by one second, will adjust the other time variables as needed
    void advanceTime();

    //Getter function for the hospital, will be used to access the Hospital's variables and child classes
    Hospital getHospital() {return mainHospital;}

    //A getter function for the resident list, will return the citizen based on their last name
    //Will be static so the providers and hospital can look up citizens. There won't be a problem as there is only one set of names
    static std::string getFirst(std::string lastName) {return residentList[lastName];}

    //Function that will go through the citizen list and see if any of them get sick 
    void sickCheck(); 

    //Function that will run a simulation over a week
    void runWeek(); 
};

#endif