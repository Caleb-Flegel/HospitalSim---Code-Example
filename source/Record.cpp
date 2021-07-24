//Cpde for the Record class's methods

//Importing thr header file
#include "../headers/Record.h"

//Constructor that will be provided arguments from the hospital class
//Gets the full name of the patient, priority of the treatment, and the time the treatment was finished
Record::Record(Patient treatedPat): name(treatedPat.getName() + " " + Town::getFirst(treatedPat.getName())), priority(treatedPat.getPriority()) {
    //Set the time
    //Note had to use temps as the - operator didn't like working with the getters
    Time temp1 = Town::getTime();
    Time temp2 = treatedPat.getStartTime();
    totalTime = (temp1 - temp2);  
}

//Getters for the class variables
std::string Record::getName () {return name;}
int Record::getPriority() {return priority;}
Time Record::getTotalTime() {return totalTime;}

//Output operator that makes outputting patient records easier in other parts of code
std::ostream& operator<< (std::ostream& out, Record& rec) {
        //Add info to the ostream
        out << rec.getName() << " was treated for a priority " << rec.getPriority() << " emergency.\n";

        //Add the time
        Time temp = rec.getTotalTime(); 
        out << "\tTotal visit time: " << temp << "\n";  

        //Return the output
        return out; 
    }