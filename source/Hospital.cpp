//Code implementation for the hospital class functions

//Importing the header
#include "..\headers\Hospital.h"

//Fucntion that will add the providers to the provider list
void Hospital::addProviders(int doctors, int nurses) {
    //Will add new instances of doctors and nurses to the providers vector using for loops
    //First the doctors
    for (int i = 0; i < doctors; i++)
    {
        providerList.push_back(new Doctor());
    }

    //Then the nurses
    for (int i = 0; i < nurses; i++)
    {
        providerList.push_back(new Nurse());
    }
}

//Function that will add a new patient to the priority list
void Hospital::newPatient(std::string lastName) {
    
}

//Function that adds a treatment to the record
void addTreatment (Patient patient);