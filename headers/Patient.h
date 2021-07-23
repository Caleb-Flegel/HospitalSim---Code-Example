//Header file for the patient class, which will store the priority and surname for each patient

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string> 


class Patient
{
private:
    //Surname for the patient
    std::string surName; 

    //Priority for the patient
    int priority; 

public:
    //Base constructor that will fill in base stats
    Patient(): surName("Undefined"), priority(-1) {}

    //Constructor that will be fed with a name and generate a random priority
    Patient(std::string name); 

    //Getters for the name and priority
    std::string getName() {return surName;}
    int getPriority() const {return priority;}
    
};

    //> operator that will allow for the patient class to be used in a priority queue
    bool operator> (const Patient& pat1, const Patient& pat2);

    //< operator that will be used in the priority queue of patients
    bool operator< (const Patient& pat1, const Patient& pat2);

#endif