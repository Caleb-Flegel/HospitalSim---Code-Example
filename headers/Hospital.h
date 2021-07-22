//Header file for the hospital class, which will keep the providers, patients, and their records

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "iostream"
#include "vector"
#include "queue"

//Import the associated classes
#include "Patient.h"
#include "Record.h"
#include "Provider.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Town.h"

class Hospital
{
private:
    //Create aa vector of providers, so the user can input how many doctors and nurses they want
    std::vector<Provider> providerList; 

    //A vector of patient records for displaying later
    //Needs to be static so the providers can add to the records
    static std::vector<Record> patientRecords; 

public:
    //Default noargs constructor, the number of doctors and nurses will be filled later
    Hospital() {}

    //Getter for the patient records, which will allow for the printing of the records
    std::vector<Record> getRecords() {return patientRecords;}

    //Create a priority queue for a patient list
    //Will be accessed by sub provider classes & there is only one hospital object, so it will be static
    static std::priority_queue<Patient>listOfPatients; 

    //Fucntion that will add the providers to the provider list
    void addProviders(int doctors, int nurses); 

    //Function that will add a new patient to the priority list
    void newPatient(std::string lastName); 

    //Function that adds a treatment to the record
    //Will be static, so it can be used by the hospital's providers
    static void addTreatment (Patient patient);

    //Function will check through the patient list to see if a citizen is in the queue 
    //Will be used with the Town's sick check method to make sure residents don't get sick twice
    bool patCheck (std::string name); 

    //Function that will run through the provider's actions, either treating their current patient or taking in a new patient
    void providerDuties();
};

#endif