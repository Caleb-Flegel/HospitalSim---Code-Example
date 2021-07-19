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
    std::map <std::string, std::string> residentList; 

    //Has one hospital object
    Hospital mainHospital; 

    //Time variables that keep track of the time
    int second;
    int minute;
    int hour;
    int day;

public:
    Town() {}

    //Function that pulls the names of the town's citizens
    void pullCitizens(); 

    //Getter function that gets converts the time to a string to be used in cout statements
    std::string getTime();
    
    //Setter function that advances the time by one second, will adjust the other time variables as needed
    void advanceTime();

    //Getter function for the hospital, will be used to access the Hospital's variables and child classes
    Hospital getHospital() {return mainHospital;}

    //A getter function for the resident list, will return the citizen based on their last name
    std::string getresident(std::string lastName) {return residentList[lastName];}
};

#endif