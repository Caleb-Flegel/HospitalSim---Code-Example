//Class header file for the town, which will contain the hospital and all of the residents

#ifndef TOWN_H
#define TOWN_H

#include <iostream>
#include <map> 
#include <string>
#include <fstream>

//Prototype for town class
class Town;

//Import the hospital class
#include "Hospital.h"

//Import time so the town can store the current time
#include "Time.h"

class Town
{
private:
    //Will have a map for the list of citizens
    //Will be static so it can be accessed by a getter
    static std::map <std::string, std::string> residentList; 

    //Has one hospital object
    Hospital *mainHospital; 

    //Current time
    static Time currentTime;

    //Variable that will store the chance per second that a resident will need to visit the emergency room
    int emergencyChnce; 

public:
    //Consructor, which will take the number of desired doctors and nurses and pass it to the hospital class as well as fill the resident list map
    //sickChance will be a chance to get sick per day, will be converted to seconds in constructor 
    Town(int docNum, int nurNum, int sickChance);
    
    //Deconstructor will delete the mainHospital pointer
    ~Town();

    //Function that pulls the names of the town's citizens
    void pullCitizens();  

    //Getter function for the hospital, will be used to access the Hospital's variables and child classes
    Hospital getHospital();

    //Getter for the current time
    //Static so it can be accessed by the patient and record classes
    static Time getTime();

    //A getter function for the resident list, will return the citizen based on their last name
    //Will be static so the providers and hospital can look up citizens. There won't be a problem as there is only one set of names
    static std::string getFirst(std::string lastName) {return residentList[lastName];}

    //Function that will go through the citizen list and see if any of them get sick 
    void sickCheck(); 

    //Function that will run a simulation over a week
    void runWeek(); 
};

#endif