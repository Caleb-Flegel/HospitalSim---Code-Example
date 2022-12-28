//Importing the classes to access their fuctions
#include "../headers/Town.h"

//Importing the googletest library
#include "gtest/gtest.h"

TEST (timeFunction, OneDayTest) {
    
    //Creating a time object 
    Time temp;

    //For loop will advance the time 1 day
    for (int i = 0; i < 1500; i++)
    {
        temp.advanceTime();
    }

    //Make sure the day has advanced
    ASSERT_GT(temp.getDay(), 0);
}

//Will make sure there are patients treated after 7 days
TEST (recordList, OneWeekTest) {
    //Creating the town object with 2 nurses, 1 doctor, and 10 patients per hour
    Town temp(2, 1, 10);

    //run the week
    temp.runWeek();

    //Make sure patients have been treated
    ASSERT_GT(temp.getHospital().getRecords().size(), 0);
}

//Making sure doctors take a patient
TEST (providers, DoctorTake){
    //Create town with 1 doctor 
    Town tempTown (1, 0, 3); 

    //Run the week
    tempTown.runWeek(); 

    //Expect that the doctor took a patient, which means the the remainign treat time is not -1
    ASSERT_GT(tempTown.getHospital().getProviders()[0]->getTreatTime(), -1);
}

//testing main function
//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}