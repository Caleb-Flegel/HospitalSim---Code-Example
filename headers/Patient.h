//Header file for the patient class, which will store the priority and surname for each patient

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using std::string; 


class Patient
{
private:
    //Surname for the patient
    string name; 

    //Priority for the patient
    int priority; 

public:
    //Base constructor that will fill in base stats
    Patient(): name("Undefined"), priority(-1) {}

    //Constructor that will be fed with a name and generate a random priority
    Patient(std::string name); 

    //Getters for the name and priority
    string getName() {return name;}
    int getPriority() {return priority;}
    
};

//> operator that will allow for the patient class to be used in a priority queue
bool std::operator> (Patient& pat1, Patient& pat2) {
    //Will check if the patient has a higher priority than it's checked counterpart
    return pat1.getPriority() >= pat2.getPriority();
}

#endif