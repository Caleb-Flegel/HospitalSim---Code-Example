//Code implementation for the hospital class functions

//Importing the header
#include "..\headers\Hospital.h"

#include "..\headers\Doctor.h"
#include "..\headers\Nurse.h"
#include "..\headers\Town.h"

//Defining static variables here so the methods can use them
std::vector<Record> Hospital::patientRecords; 
std::priority_queue<Patient> Hospital::listOfPatients; 

//Support function will convert inputted last names to uppercase so the input will be recognized with the patient records and resident map
void Hospital::toUppercase (std::string& input){
    //for loop will go through each letter and convert it to uppercase if needed
    for (int i = 0; i < input.size(); i++)
    {
        if ((input[i]> 96) && (input[i] < 123)) {
            //Convert the letter to uppercase
            input[i] -= 32;
        }
    } 
}

//Getter that will get the size of the queue
int Hospital::getPatientcount() {return listOfPatients.size();}

//Getter that will get the patient off the top of the queue and remove it to get another patient
Patient Hospital::getPatient() {
    Patient P = listOfPatients.top();
    listOfPatients.pop();
    return P;
}

//Setter that adds a patient back to the queue
void Hospital::pushPatient(Patient P) {
    listOfPatients.push(P);
}

//Fucntion that will add the providers to the provider list
void Hospital::addProviders(int doctors, int nurses) {
    //Will add new instances of doctors and nurses to the providers vector using for loops
    //First the doctors
    for (int i = 0; i < doctors; i++)
    {
        providerList.push_back(new Doctor());
    }

    //Then the nurses
    for (int i = 0; i < nurses; i++)
    {
        providerList.push_back(new Nurse());
    }
}

//Function that will add a new patient to the priority queue
void Hospital::newPatient(std::string lastName) {
    //Will push a new patient to the queue using the patient's consructor, which will determine a priority
    listOfPatients.push(Patient(lastName));   
}

//Function that will search if a last name is in the patient record, will return true if there is a match
bool Hospital::searchPatient(std::string lastName) {
    //Convert the inputted last name to uppercase for the search
    toUppercase(lastName);

    //Make a full name string as that is how the name is stored in the records
    std::string fName = lastName + " " + Town::getFirst(lastName);

    //For loop will search thru the patient records and see if the name is there
    for (int i = 0; i < patientRecords.size(); i++) {
        
        //See if there is a match
        if (fName == patientRecords[i].getName()) {
            //Return true as there is a match
            return true;
        }
    }

    //Means a match wasn't found, return false
    return false; 
}

//Function that will print all records containing an inputted last name
void Hospital::printNameRecord(std::string lastName){
    //Convert the last name to uppercase
    toUppercase(lastName);

    //get the full name of the resident for looking up in the records
    std::string fName = lastName + " " + Town::getFirst(lastName); 

    //For loop will go through record and print any record
    for (int i = 0; i < patientRecords.size(); i++)
    {
        //Check to see if the full name matches the one in the record
        if (patientRecords[i].getName() == fName) {
            //Print the record
            std::cout << patientRecords[i] << "\n"; 
        }
    }
}

//Function that adds a treatment to the record
void Hospital::addTreatment (Patient patient) {
    
    //Add a new record using the name, priority, and treatment time of the the patient
    patientRecords.push_back(Record(patient));
}

//Function that will calculate the average treatment time of all completed patients' treatment times
Time Hospital::getAvgTreatment() {
    //total time object will keep track of the full time
    Time total; 

    //Temp time will store the time that will be added to the total time, used since the + operator doesn't like working with the getter
    Time temp;

    //For loop will add time to the total time
    for (int i = 0; i < patientRecords.size(); i++)
    {
        //Getting the time from the current record
        temp = patientRecords[i].getTotalTime();

        //Add temp to the total time
        total = total + temp; 
    }

    //minutes function that will store the total minutes
    int totMinutes = total.toMinutes(total);

    //Divide totMinutes by the number of records to get the avg total minutes
    totMinutes /= patientRecords.size();  

    //Use temp to make a new temp time object with the average number of minutes
    temp = Time(0, 0, totMinutes); 

    //Adjust the temp time to convert the minutes to hours and days 
    temp(); 

    //Return the temp time
    return temp; 
}

//Function will check through the patient list to see if a citizen is in the queue 
//Will be used with the Town's sick check method to make sure residents don't get sick twice
bool Hospital::patCheck (std::string name) {
    //Create a check bool that will be returned true if the imputted name is already a patient. Assuming the patient doesn't exist
    bool check = false; 

    //Reset vector will be used to put all of the patients back into the queue after checking
    std::vector<Patient> reset; 

    //For loop will go through the priority_queue and check the names
    for (int i = 0; i < listOfPatients.size(); i++)
    {
        //Create a temp patient which will be checked against the argument name
        Patient temp = listOfPatients.top(); 

        //Add the temp patient to the reset vector and remove it from the queue
        reset.push_back(temp);

        listOfPatients.pop();         

        //Check to see if the names match
        if (temp.getName() == name) {
            //set check to true and break the loop
            check = true;

            break;
        }
    }

    //Another for loop will add the reset vector patients back into the queue
    for (int i = 0; i < reset.size(); i++)
    {
        listOfPatients.push(reset[i]); 
    }
    
    //Return the results of the check
    return check; 
}

//Function that will run through the provider's actions, either treating their current patient or taking in a new patient
void Hospital::providerDuties() {
    
    //Go through the vector of providers and determine their action
    for (int i = 0; i < providerList.size(); i++)
    {
        //Check to see if the provider is avaliable
        if (providerList[i]->isAvalible()) {
            //Get a new patient if there is one available to be treated
            providerList[i]->setTreatment(); 
        }
        else {
            //Means the provider is in the middle of treating a patient, so treatment will continue
            //Run the treat function which will decrease the remaining treatment time and create a record if needed
            providerList[i]->treatPatient();
        }
    }
}

//Function for testing, will pull the providers
std::vector<Provider*> Hospital::getProviders() {
    return providerList;
}