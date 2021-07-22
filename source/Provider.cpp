//Code for the provider, doctor, and nurse classes

//Importing the class 
#include "../headers/Provider.h"
#include "../headers/Doctor.h"
#include "../headers/Nurse.h"

//Importing town.h to get to the time variables & hospital.h to get to the patient queue

//A function that will allow "treatment" of the patient by decreasing the remaining time and set the availibility to true if needed
void Provider::treatPatient(){
    //Decrease the time remaining 
    remainingTreatTime --; 

    //Will check if the treatment is finished
    if (remainingTreatTime <= 0) {
        //Set availability to true
        avalible = true; 

        //Add the patient to the record
        Hospital::addTreatment(currentPatient);
    }
}

//Doctor version of the function that will set up treating the patient
void Doctor::setTreatment(){

    //Making sure there is a patient waiting before pulling the patient
    if (Hospital::listOfPatients.size() > 0) {

        //Will pull the patient from the top of the queue and set them as the current patient
        //There is no need to check the priority as a doctor can treat any priority
        currentPatient = Hospital::listOfPatients.top(); 

        //Will pop the current patient so no other provider takes the same patient
        Hospital::listOfPatients.pop(); 

        //Generate a random treatment time between 1 and 20 minutes
        remainingTreatTime = (rand() % 20) + 1;

        //Multiply treatment time by 60 to convert minutes to seconds
        remainingTreatTime *= 60;

        //Set availible to false so there isn't another patient chosen
        avalible = false;
    }
}

//Nurse version of the function that will set up treating the patient
void Nurse::setTreatment() {
    //Creating a temporary patient variable
    Patient temp;

    //A vector of patients that the nurse would be unable to treat and will need to be added back into the list of patients
    std::vector <Patient> passedPats; 

    //Will pull patients until the nurse gets a patient that they are able to treat or the list runs out
    while (Hospital::listOfPatients.size() > 0)
    {
        //Pull the top patient from the list
        temp = Hospital::listOfPatients.top(); 

        //Erase the temp patient from the list
        Hospital::listOfPatients.pop();

        //Check if the patient is able to be treated by the nurse
        if (temp.getPriority() < 11) {
            //Set the temp patient as the current patient
            currentPatient = temp; 

            //Set a random treatment time between 1 and 10 minutes
            remainingTreatTime = (rand() % 10) + 1;
            remainingTreatTime *= 60; 

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
        Hospital::listOfPatients.push(passedPats[i]); 
    }
}