//A provider class that will be a parent class for seperate doctor and nurse classes 

#ifndef PROVIDER_H
#define PROVIDER_H

#include <iostream>

//Including the patient class as a provider will hold the patient they are treating
#include "Patient.h"

//Including hospital so the providers can access the patient list
#include "Hospital.h"

class Provider
{
protected:
    //Current patient that the provider is treating
    Patient currentPatient; 

    //Flag to see if they are open for another patient
    bool avalible;

    //int that will track what the remaining treat time is
    int remainingTreatTime; 

public:
    //Base constructor will set the availibility flag to true and set remaining treat time to -1, which means they can take a patient
    Provider(): avalible(true), remainingTreatTime(-1) {}

    //Virtual function that will set up treating the patient, will be different depending on if the provider is a doctor or nurse
    virtual void setTreatment() = 0; 

    //A function that will allow "treatment" of the patient by decreasing the remaining time and set the availibility to true if needed
    void treatPatient(); 

    //getter that will check if the provider is availible
    bool isAvalible() {return avalible;} 

    //Getter that will return the current patient
    Patient getPatient() {return currentPatient;}
};

#endif