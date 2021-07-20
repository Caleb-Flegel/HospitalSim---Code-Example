//Code for the treat patient function for the provider class

//Importing the class 
#include "../headers/Provider.h"

//A function that will allow "treatment" of the patient by decreasing the remaining time and set the availibility to true if needed
void Provider::treatPatient(){
    //Decrease the time remaining 
    remainingTreatTime --; 

    //Will check if the treatment is finished
    if (remainingTreatTime >= 0) {
        //Set availability to true
        avalible = true; 
    }
}