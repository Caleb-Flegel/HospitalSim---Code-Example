//Code implementation for the patient constructor

//Importing the header
#include "..\headers\Patient.h"

//Constructor that will be fed with a name and generate a random priority
Patient::Patient(std::string name): name(name) {
    //Will generate a random number between 0 and 9
    int priorityChk = rand() % 10;

    //Switch statement will determine which priority will be set for the 
    switch (priorityChk)
    {
    //Will go to the low-priority section 70% of the time 
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        //Generate a priority between 1 and 10 and assign it to the priority
        priority = (rand() % 10) + 1; 

        break;
    
    //Generate a medium priority 20% of the time
    case 7:
    case 8:
        //Generate a priority between 11 and 15
        priority = (rand() % 5) + 11;

        break;
    
    //High priority is generated 10% of the time
    case 9:
        //Priority is between 16 and 20
        priority = (rand() % 5) + 16;

        break;
    
    default:
        break;
    }
}