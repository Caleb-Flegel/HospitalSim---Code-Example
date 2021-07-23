//Header for the Nurse child class, which is a child to the provider class

#ifndef NURSE_H
#define NURSE_H

#include <iostream>

//Import the provider class
#include "Provider.h"

class Nurse: public Provider
{
private:
    
public:
    //No args constructor, which will also call the parent class constructor, which doesn't have any arguments either
    Nurse() {}

    //Nurse version of the set treatment function
    //note: code in provider.cpp
    void setTreatment();
};


#endif