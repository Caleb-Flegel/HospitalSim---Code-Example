//Header file for the record class, which will store all treatments done

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

//Importing town.h, so the class can access the first names of patients and time of the treatment
#include "Town.h"

class Record
{
private:
    //Store the name of the patient
    std::string name; 
    
    //Store the priority of the patient
    int priority;

    //Store the string form of the time of treatment
    std::string time; 
public:

    //Constructor that will be provided arguments from the hospital class
    Record(std::string last, int priority, std::string time): name(last + " " + Town::getFirst(last)), priority(priority), time(Town::getTime()) {}

    //Getters for the variables
    std::string getName () {return name;}
    int getPriority() {return priority;}
    std::string getTime() {return time;}
};

//<< Operator overload that will print the record of the treatment
std::ostream& std::operator<<(std::ostream& out, Record& rec) {
    //Add info to the ostream
    out << rec.getName() << " was treated for a priority " << rec.getPriority() << " emergency on " << rec.getTime(); 

    //Return the output
    return out; 
}

#endif