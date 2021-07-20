//Header file for the hospital class, which will keep the providers, patients, and their records

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "iostream"
#include "vector"
#include "queue"

//Import the associated classes
#include "Patient.h"
#include "Record.h"

class Hospital
{
private:
    //Create aa vector of providers, so the user can input how many doctors and nurses they want
    std::vector<Providers> providerList; 

    //Create a priority queue for a patient list
    std::priority_queue<Patient, std::vector<Patient>, std::less<std::vector<Patient>::value_type>>listOfPatients; 

    //A vector of patient records for displaying later
    std::vector<Record> patientRecords; 

public:
    //Default constructor that will take in the number of doctors and nurses requested
    Hospital(int doctors, int nurses) {addProviders(doctors, nurses);}

    //Fucntion that will add the providers to the provider list
    void addProviders(int doctors, int nurses); 

    //Function that will add a new patient to the priority list
    void newPatient(std::string lastName); 

    //Function that adds a treatment to the record
    void addTreatment (Patient patient);
};

#endif