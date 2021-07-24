//Header file for the patient class, which will store the priority and surname for each patient

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string> 

class Patient;

//Including time so the patient can store the time they started entered the hospital and the treatment time
#include "Time.h"

class Patient
{
private:
    //Surname for the patient
    std::string surName; 

    //Priority for the patient
    int priority; 

    //Time when the patient entered the queue
    Time startTime;

public:
    //Base constructor that will fill in base stats
    Patient(): surName("Undefined"), priority(-1) {}

    //Constructor that will be fed with a name and generate a random priority
    Patient(std::string name); 

    //Getters for the patients details
    std::string getName() {return surName;}
    int getPriority() const {return priority;}
    Time getStartTime() {return startTime;}
    
};

    //> operator that will allow for the patient class to be used in a priority queue
    bool operator> (const Patient& pat1, const Patient& pat2);

    //< operator that will be used in the priority queue of patients
    bool operator< (const Patient& pat1, const Patient& pat2);

#endif