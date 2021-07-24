//Code for the Nurse version of the setTreatment method

//Including the Nurse header file and Hospital so the method can access the patient list
//Nurse version of the function that will set up treating the patient
#include "../headers/Nurse.h"
#include "../headers/Hospital.h"


void Nurse::setTreatment() {
    //Creating a temporary patient variable
    Patient temp;

    //A vector of patients that the nurse would be unable to treat and will need to be added back into the list of patients
    std::vector <Patient> passedPats; 

    //Will pull patients until the nurse gets a patient that they are able to treat or the list runs out
    while (Hospital::getPatientcount() > 0)
    {
        //Pull the top patient from the list
        temp = Hospital::getPatient();

        //Check if the patient is able to be treated by the nurse
        if (temp.getPriority() < 11) {
            //Set the temp patient as the current patient
            this -> currentPatient = temp; 

            //Set a random treatment time between 1 and 10 minutes
            remainingTreatTime = (rand() % 10) + 1;

            //Set availability to false
            avalible = false;

            //Break the loop
            break; 
        }
        else {
            //Means the patient is unable to be treated, so they will be added to the passed vector
            passedPats.push_back(temp); 
        }
    }

    //For loop will push all passed patients back into the priority queue
    for (int i = 0; i < passedPats.size(); i++)
    {
        Hospital::pushPatient(passedPats[i]); 
    }
}