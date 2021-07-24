//Header file for the record class, which will store all treatments done

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

//Prototype for the class so other classes can function
class Record;

//Importing town.h, so the class can access the first names of patients and time of the treatment
#include "Town.h"

class Record
{
private:
    //Store the name of the patient
    std::string name; 
    
    //Store the priority of the patient
    int priority;

    //Store the total time of treatment
    Time totalTime; 

public:

    //Constructor that will be provided arguments from the hospital class
    Record(Patient treatedPat);

    //Getters for the variables
    std::string getName ();
    int getPriority();
    Time getTotalTime();
};

//<< Operator overload that will print the record of the treatment
std::ostream& operator<< (std::ostream& out, Record& rec);

#endif