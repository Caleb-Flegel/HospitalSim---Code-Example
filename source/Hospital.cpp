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

//Function that will add a new patient to the priority queue
void Hospital::newPatient(std::string lastName) {
    //Will push a new patient to the queue using the patient's consructor, which will determine a priority
    listOfPatients.emplace(new Patient(lastName));   
}

//Function that adds a treatment to the record
void Hospital::addTreatment (Patient patient) {
    //Add a new record using the name, priority, and treatment time of the the patient
    patientRecords.push_back(new Record(patient.getName(), patient.getPriority()))
}