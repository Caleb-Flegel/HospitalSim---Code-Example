// Caleb Flegel
// 7/17/21
// <Course Code: CS-273-ACOL> 
// License: Copyright 2021 Caleb Flegel 
// Resources used: Book, C++ reference.com, Pete, Class Notes
// Worked with: Pete Tucker on help with multiple issues
// Final, 

#include <iostream>
//#include <ctime>
//#include <cstdlib> 
//Note: Tried to use these with srand(time(NULL)) but encountered odd build errors that I was not able to resolve

//Importing the needed classes
#include "../headers/Town.h"

using std::cout;

int main () {

    //Seeding random number generator 
    //Note: Wanted to seed random number, encountered build errors I was never able to figure out
    //srand(time(NULL));

    //Input variable that would collect the user's inputs
    int setUpInput; 

    //Bool that makes sure the user's input was valid
    bool valid; 

    //Variables determined by the user that will be plugged into the simulation
    int infectRate, docNum, nurNum; 

    //Intro cout
    cout << "Welcome to the hospital simulation!\n";

    //Do while loop will get a valid input for the infection rate
    do {
        cout << "\nWhat will be the infection rate, AKA how many people will get sick per hour? (1-60) ";
        std::cin >> setUpInput; 

        //Check to make sure the input was valid
        if ((setUpInput > 0) && (setUpInput < 61)) {
            //Set the input to the infection variable
            infectRate = setUpInput;

            //Flag that there was a valid input
            valid = true;
        }
        else {
            //Invalid input, mark the valid flag as false
            valid = false; 
        }

    } while (valid == false);

    //Another do while loop will collect how many doctors there should be
    do {
        //Collect the user's input
        cout << "\nHow many doctors will there be? ";
        std::cin >> setUpInput; 

        //Check to make sure the input was valid
        if (setUpInput > 0) {
            //Set the doctor num to the number that the user inputted
            docNum = setUpInput;

            //Flag that there was a valid input
            valid = true;
        }
        else {
            //Invalid input, mark the valid flag as false
            valid = false; 
        }

    } while (valid == false);

    //Final do while loop will get the number of nurses from the user
    do {
        //Collect the user's input
        cout << "\nHow many nurses will there be? ";
        std::cin >> setUpInput; 

        //Check to make sure the input was valid
        if (setUpInput > 0) {
            //Set the nurse num to the number that the user inputted
            nurNum = setUpInput;

            //Flag that there was a valid input
            valid = true;
        }
        else {
            //Invalid input, mark the valid flag as false
            valid = false; 
        }

    } while (valid == false);

    //Let the user know that the simulation will run
    cout << "\n\n\bInputs saved, running simulation...\n\n";

    //Creating the town object with the user inputs
    Town mainTown(docNum, nurNum, infectRate);

    //Run the simulation with the inputs
    mainTown.runWeek(); 

    //Line breaks for console clarity 
    std::cout << "\n\n\n";

    //Seperate bool will track to see if the user wants to end the program
    bool end = false;

    //New input variable will take in the user's input strings 
    std::string input;

    //The average time for the patient's treatment will stored here
    Time avgTreatment = mainTown.getHospital().getAvgTreatment();  

    //status update message
    cout << "Simulation completed!\n";

    //While loop will allow the user to look at treatments 
    while (end == false)
    {
        //Display stats to the user
        cout << "\nTotal treatments completed: " << mainTown.getHospital().getRecords().size() << "\tAverage treatment time: " << avgTreatment; 

        //Ask what the user wants to do with the records
        cout << "\nWhat do you wish to do with the records? (\"see all records\", \"name lookup\", or \"end\") ";
        getline(std::cin, input);

        //If statements will process the request
        if (input == "see all records") {
            //Letting the user know that all records will be printed
            cout << "\nAll records printing...\n";

            //Printing all patient records using a for loop
            for (int i = 0; i < mainTown.getHospital().getRecords().size(); i++)
            {
                std::cout << mainTown.getHospital().getRecords()[i] << "\n";
            }
        }
        else if (input == "name lookup") {
            //Check with the user to see which name they want to look up
            cout << "\nWhich last name do you want looked up in the patient record? ";
            std::cin >> input; 

            //Checking to see if the name has been a patient
            if (mainTown.getHospital().searchPatient(input)) {
                
                //Means a patient was found, will print all patient records with that name
                cout << "\nAll records with the last name " << input << "\n";
                mainTown.getHospital().printNameRecord(input); 

            }
            else {
                //Means the inputted name wasn't found in the records
                cout << "\n" << input << " was not found in hospital records.\n";
            }
        }
        else if (input == "end") {
            //Means the user wants to end the simulation
            //Changing the end flag so the program ends
            end = true; 

            //Outgoing message
            cout << "\n\bThanks for using the hospital simulator!\n";
        }
        else {
            //Input was not recognized, will let the user know
            cout << "\nInput not recognized!\n"; 
        }
    }   

    return 0;
}