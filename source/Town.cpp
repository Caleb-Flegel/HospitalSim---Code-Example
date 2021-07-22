//Code implementation for the town class header file

//importing the file
#include "..\headers\Town.h"

//Function that pulls the names of the town's citizens
void Town::pullCitizens(){
    //Create string variables that will hold the first and last names of the citizens
    std::string first;
    std::string last; 

    //Create two input file stream objects to read the from the name documents
    std::ifstream firstInput;
    std::ifstream lastInput;

    //Open the files using the streams
    firstInput.open("residents_of_273ville.txt");
    lastInput.open("surnames_of_273ville.txt");

    //While loop will run through the documents and fill out the names
    while (!lastInput.eof()) {
        //Collect the names
        lastInput >> last; 
        firstInput >> first; 

        //Add the name to the map 
        residentList[last] = first; 
    }
}

//Function that gets converts the time to a string to be used in cout statements
void Town::setTime() {
    //Create a return string
    std::string disp; 

    //Add the date first
    disp += "Day " + std::to_string(day);

    //Then the time
    disp += ", " + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second); 

    //set the string time to the object's time variable
    time = disp; 
}

//Getter that returns the string form of time
std::string Town::getTime() {
    //Will update the string time 
    setTime();

    //return the updated string time
    return time;
}

//Setter function that advances the time by one second, will adjust the other time variables as needed
void Town::advanceTime() {
    //Add one to seconds
    second ++; 

    //Check to see if the minute needs to be adjusted
    if (second >= 60) {
        //Add one to minute
        minute ++;

        //Set seconds to 0 to start the next minute
        second = 0;

        //Check to see if the hour needs to be adjusted
        if (minute >= 60) {
            //Add an hour
            hour ++;
            
            //Reset the minutes
            minute = 0; 

            //Check to see if a day will advance
            if (hour >= 24) {
                //add one day
                day ++; 

                //Reset the hours counter
                hour = 0; 
            }
        }
    }
}

//Function that will go through the citizen list and see if any of them get sick 
void Town::sickCheck() {
    //Create an iterator that will run through the map
    std::map<std::string, std::string>::iterator iter = residentList.begin(); 

    //For loop will run through the residentList map
    for (int i = 0; i < residentList.size(); i++)
    {
        //Check to see if the resident gets sick by seeing if they roll a one in x chance
        if ((rand() % emergencyChnce) == 0) {
            //Means the resident was unlucky and will get sick or is already sick.

            //Another check will make sure the resident isn't already a patient
            if (!mainHospital.patCheck(iter -> first)) {
            
                //Method will send the resident's last name to the hospital, which will create a patient
                mainHospital.newPatient(iter -> first);
            }
        }
        //Go to the next name in the map
        iter++; 
    }
}

//Function that will run a simulation over a week
void Town::runWeek() {
    //Print num will be used to be used to help print the right patient records
    int printNum = 0; 

    //Will run until the day hits 7, which, since it starts at 0, will mean a week has passed
    while (day < 7)
    {
        //Each pass by this while loop will consitute a second of simulation
        //Each second, each resident may get sick and the providers will either treat their patient or take in a new one when available

        //Checking if any citizen gets sick, if any do, they will be added to the hospital's patient list
        sickCheck(); 

        //Allow the providers to do their duties, either take in a new patient or treating their current patients
        mainHospital.providerDuties();

        //For loop will start at the current printNum and go to the record's size so only new reports are printed
        for (int i = printNum; i < mainHospital.getRecords().size(); i++)
        {
            //Printing the new treatment records
            std::cout << std::endl << mainHospital.getRecords()[i] << std::endl;
        }

        //Advance time to the next second
        advanceTime();    
    }
    
}