//Header file for the doctor version of the setTreatment method

//IMporting doctor and hospital
//Hospital will be used to access the patient list
#include "../headers/Doctor.h"
#include "../headers/Hospital.h"

//Doctor version of the function that will set up treating the patient
void Doctor::setTreatment(){

    //Making sure there is a patient waiting before pulling the patient
    if (Hospital::getPatientcount() > 0) {

        //Will pull the patient from the top of the queue and set them as the current patient
        //There is no need to check the priority as a doctor can treat any priority
        this -> currentPatient = Hospital::getPatient(); 

        //Generate a random treatment time between 1 and 20 minutes
        this -> remainingTreatTime = (rand() % 20) + 1;

        //Set availible to false so there isn't another patient chosen
        this -> avalible = false;
    }
}