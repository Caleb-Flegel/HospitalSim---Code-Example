//Cpde for the Record class's methods

//Importing thr header file
#include "../headers/Record.h"

//Constructor that will be provided arguments from the hospital class
//Gets the full name of the patient, priority of the treatment, and the time the treatment was finished
Record::Record(std::string last, int priority, std::string time): name(last + " " + Town::getFirst(last)), priority(priority), time(Town::getTime()) {}

//Getters for the class variables
std::string Record::getName () {return name;}
int Record::getPriority() {return priority;}
std::string Record::getTime() {return time;}

//Output operator that makes outputting patient records easier in other parts of code
std::ostream& operator<< (std::ostream& out, Record& rec) {
        //Add info to the ostream
        out << rec.getName() << " was treated for a priority " << rec.getPriority() << " emergency on " << rec.getTime(); 

        //Return the output
        return out; 
    }