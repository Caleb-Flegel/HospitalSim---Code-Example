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

//Getter function that gets converts the time to a string to be used in cout statements
std::string Town::getTime() {
    //Create a return string
    std::string disp; 

    //Add the date first
    disp += "Day " + std::to_string(day);

    //Then the time
    disp += ", " + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second); 

    //return the completed time
    return disp;
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