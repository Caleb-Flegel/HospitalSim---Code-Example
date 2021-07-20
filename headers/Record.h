//Header file for the record class, which will store all treatments done

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>

class Record
{
private:
    //Store the name of the patient
    std::string name; 
    
    //Store the priority of the patient
    int priority;
public:

    //Constructor that will be provided arguments from the hospital class
    Record(std::string name, int priority, std::string time): name(name), priority(priority) {}

    //Getters for the variables
    std::string getName () {return name;}
    int getPriority() {return priority;}

    //Function that will print the the treatment report
    void printReport();
};

//<< Operator overload that will print the record of the treatment
std::ostream& std::operator<<(std::ostream& out, Record& rec) {
    //Get the name of the patient
    out << rec.getName();

    //add the priortiy and time
    out << " was treated for a priority " << rec.getPriority() << " emergency."; 

    //Return the output
    return out; 
}

#endif