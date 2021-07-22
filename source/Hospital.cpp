//Code implementation for the hospital class functions

//Importing the header
#include "..\headers\Hospital.h"

//Fucntion that will add the providers to the provider list
void Hospital::addProviders(int doctors, int nurses) {
    //Will add new instances of doctors and nurses to the providers vector using for loops
    //First the doctors
    for (int i = 0; i < doctors; i++)
    {
        providerList.emplace_back(new Doctor());
    }

    //Then the nurses
    for (int i = 0; i < nurses; i++)
    {
        providerList.emplace_back(new Nurse());
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
    patientRecords.emplace_back(new Record(patient.getName(), patient.getPriority(), Town::getTime()));
}

//Function will check through the patient list to see if a citizen is in the queue 
//Will be used with the Town's sick check method to make sure residents don't get sick twice
bool Hospital::patCheck (std::string name) {
    //Create a check bool that will be returned true if the imputted name is already a patient. Assuming the patient doesn't exist
    bool check = false; 

    //Reset vector will be used to put all of the patients back into the queue after checking
    std::vector<Patient> reset; 

    //For loop will go through the priority_queue and check the names
    for (int i = 0; i < listOfPatients.size(); i++)
    {
        //Create a temp patient which will be checked against the argument name
        Patient temp = listOfPatients.top(); 

        //Add the temp patient to the reset vector and remove it from the queue
        reset.push_back(temp);

        listOfPatients.pop();         

        //Check to see if the names match
        if (temp.getName() == name) {
            //set check to true and break the loop
            check = true;

            break;
        }
    }

    //Another for loop will add the reset vector patients back into the queue
    for (int i = 0; i < reset.size(); i++)
    {
        listOfPatients.push(reset[i]); 
    }
    
    //Return the results of the check
    return check; 
}

//Function that will run through the provider's actions, either treating their current patient or taking in a new patient
void Hospital::providerDuties() {
    
    //Go through the vector of providers and determine their action
    for (int i = 0; i < providerList.size(); i++)
    {
        //Check to see if the provider is avaliable
        if (providerList[i].isAvalible()) {
            //Get a new patient if there is one available to be treated
            providerList[i].setTreatment(); 
        }
        else {
            //Means the provider is in the middle of treating a patient, so treatment will continue
            //Run the treat function which will decrease the remaining treatment time and create a record if needed
            providerList[i].treatPatient();
        }
    }
}