//Code implementation for the town class header file

//importing the file
#include "..\headers\Town.h"

//Restablishing static variables so the methods are able to work with them
std::map <std::string, std::string> Town::residentList;
Time Town::currentTime;

//Consructor, which will take the number of desired doctors and nurses and pass it to the hospital class as well as fill the resident list map
//sickChance will be a chance to get sick per hour/average number of people to get sick per hour, will be converted to minutes in constructor 
Town::Town(int docNum, int nurNum, int sickChance): emergencyChnce(sickChance) {mainHospital = new Hospital; 
                                                                                         mainHospital->addProviders(docNum, nurNum);
                                                                                         pullCitizens();}
//Deconstructor that delete's the town's hospital
Town::~Town() {delete mainHospital;}

//Getter function for the hospital, will be used to access the Hospital's variables and child classes
Hospital Town::getHospital() {return *mainHospital;}

//Getter for the current time
Time Town::getTime() {return currentTime;}

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

//Function that will go through the citizen list and see if any of them get sick 
void Town::sickCheck() {
    //Create an iterator that will run through the map
    std::map<std::string, std::string>::iterator iter = residentList.begin(); 

    //Emergency chance is how many people should get sick per hour, so will need to convert it to minutes
    //int sickTest = emergencyChnce * 60; 

    //Chance each person is infected per hour
    double test = 2000/emergencyChnce;
    //Chance each person is infected per minute
    test /= 60; 

    //For loop will run through the residentList map
    for (int i = 0; i < residentList.size(); i++)
    {
        //So now each person has a 1 in sickTest number of getting sick per minute, so will roll a rand and see if the person gets the 1 over sickTest
        if ((rand() % static_cast<int>(10000*test)) == 0) {
            //Means the resident was unlucky and will get sick or is already sick.

            //Another check will make sure the resident isn't already a patient
            if (!mainHospital->patCheck(iter -> first)) {
            
                //Method will send the resident's last name to the hospital, which will create a patient
                mainHospital->newPatient(iter -> first);
            }
        }
        //Go to the next name in the map
        iter++; 
    }
}

//Function that will run a simulation over a week
void Town::runWeek() {

    //Will run until the day hits 7, which, since it starts at 0, will mean a week has passed
    while (currentTime.getDay() < 7)
    {
        //Each pass by this while loop will consitute a second of simulation
        //Each second, each resident may get sick and the providers will either treat their patient or take in a new one when available

        //Checking if any citizen gets sick, if any do, they will be added to the hospital's patient list
        sickCheck(); 

        //Allow the providers to do their duties, either take in a new patient or treating their current patients
        mainHospital->providerDuties();

        //Advance time to the next second
        currentTime.advanceTime();  

        //Will print when each hour passes
        if (currentTime.getMinute() == 0) {
            std::cout << "Time status: " << currentTime << "\n";
        }
    }
    
}