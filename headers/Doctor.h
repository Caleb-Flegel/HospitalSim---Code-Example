//Header for the doctor child class to the provider class
#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>

//Importing provider
#include "Provider.h"

class Doctor: public Provider {
private:
    
public:
    Doctor() {}

    //Doctor version of function that will set up treating the patient
    //Note: code in provider.cpp
    void setTreatment();
};

#endif 