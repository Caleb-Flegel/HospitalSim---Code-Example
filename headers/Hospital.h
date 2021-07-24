//Header file for the hospital class, which will keep the providers, patients, and their records

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <vector>
#include <queue>

//Prototype for the Hospital class that allows other classes to function without "knowing" hospital
class Hospital;

//Import the associated classes
#include "Patient.h"
#include "Record.h"
#include "Provider.h"

class Hospital
{
private:
    //Create aa vector of providers, so the user can input how many doctors and nurses they want
    std::vector<Provider*> providerList; 

    //A vector of patient records for displaying later
    //Needs to be static so the providers can add to the records
    static std::vector<Record> patientRecords; 

    //Create a priority queue for a patient list
    //Will be accessed by sub provider classes & there is only one hospital object, so it will be static
    static std::priority_queue<Patient>listOfPatients; 

    //Support function will convert inputted last names to uppercase so the input will be recognized with the patient records and resident map
    void toUppercase (std::string& input);

public:
    //Default noargs constructor, the number of doctors and nurses will be filled later
    Hospital() {}

    //Getter for the patient records, which will allow for the printing of the records
    std::vector<Record> getRecords() {return patientRecords;}

    //Getters and setters needed for sub-classes to access the list of patients
    static int getPatientcount();
    static Patient getPatient();
    static void pushPatient(Patient P);

    //Fucntion that will add the providers to the provider list
    void addProviders(int doctors, int nurses); 

    //Function that will add a new patient to the priority list
    void newPatient(std::string lastName); 

    //Function that will search if a last name is in the patient record
    bool searchPatient(std::string lastName);

    //Function that will print all records containing an inputted last name
    void printNameRecord(std::string lastName);

    //Function that adds a treatment to the record
    //Will be static, so it can be used by the hospital's providers
    static void addTreatment (Patient patient);

    //Function that will calculate the average treatment time of all completed patients' treatment times
    Time getAvgTreatment();

    //Function will check through the patient list to see if a citizen is in the queue 
    //Will be used with the Town's sick check method to make sure residents don't get sick twice
    bool patCheck (std::string name); 

    //Function that will run through the provider's actions, either treating their current patient or taking in a new patient
    void providerDuties();

    //Function for testing, will pull the providers
    std::vector<Provider*> getProviders();
};

#endif