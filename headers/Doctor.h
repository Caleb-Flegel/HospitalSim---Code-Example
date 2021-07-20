//Header for the doctor child class to the provider class

#ifndef DOCTOR_H
#define DOCTOR_H

//Importing provider
#include "Provider.h"

#include <iostream>

class Doctor: public Provider
{
private:
    
public:
    Doctor(): Provider() {}

    //Doctor version of function that will set up treating the patient
    void setTreatment();
};

#endif 