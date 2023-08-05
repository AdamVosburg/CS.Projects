/* 
* Chada Tech Clock Project 1
* Adam Vosburg
* 07/09/2023
*/

#include <iostream> //This will include the iostream library.  This gives both output and input functionality
#include <ctime>    //Had to google this.  It includes a ctime library which provides dates and time functionality
#include <iomanip> //Also googled this.  This library allows me to manipulate the output times using the put_time seen later in the code

//Informs compiler to use standard library for naming conventions like cout, cin, without using std::
using namespace std;  

/*
* ShowTime() is a function that declares two constant character pointers, clockTime12 and clockTime24
* and inputs them into a "clock face". 
* The code can then be manipulated in the main function
*/
void ShowTime(tm* timeinfo) { // timeinfo pointer used here with a tm struct which holds a date and time
    const char* clockTime12 = "%I:%M:%S %p"; //This format is used in put_time.  The specifiers are %I = hour, %M = Minute, %S = seconds and %p = period such as AM and PM
    const char* clockTime24 = "%H:%M:%S";

// put_time function from the <iomanip> library takes timeinfo pointer and formats the above parmameters into the clokcface
    cout << "********************************" << "   " << "*****************************" << endl;
    cout << "*         12-HR Clock          *" << "   " << "*        24-HR Clock        *" << endl;
    cout << "*         " << std::put_time(timeinfo, clockTime12) << "          *   " << "*         " << std::put_time(timeinfo, clockTime24) << "          *" << endl;
    cout << "********************************" << "   " << "*****************************" << endl;
}
/* 
* ClockMenu function prints the current menu option to call after every userInput in the main function.
* This will be called to iterate after the while loop proior to user input..
*/
void ClockMenu() {
   
    
    cout << "**************************" << endl;
    cout << "*                        *" << endl;
    cout << "*    1.) Add 1 Hour      *" << endl;
    cout << "*                        *" << endl;
    cout << "*    2.) Add 1 Min.      *" << endl;
    cout << "*                        *" << endl;
    cout << "*    3.) Add 1 Sec.      *" << endl;
    cout << "*                        *" << endl;
    cout << "*    4.) Quit clock      *" << endl;
    cout << "*                        *" << endl;
    cout << "**************************" << endl;

}   


// These three functions can be called to add an hour, minute or second to the clock face from a simple switch case in the main menu

void addHour(struct tm* timeinfo) {
    timeinfo->tm_hour += 1;
}

void addMinute(struct tm* timeinfo) {
    timeinfo->tm_min += 1;
}

void addSecond(struct tm* timeinfo) {
    timeinfo->tm_sec += 1;
}

/*
* The following is the main program which takes a current time from <ctime> and allows the User
* to manipulate the time as they see fit until they decide to terminate the program.
* Further details epxlain individual actions of the prorgam
*/

int main() {
    time_t now = time(0); //This sets up the time in the main using <ctime> and sets time to 0 seconds
    tm* timeinfo = localtime(&now); // this function which is also in <ctime> coverts time_t to a tm struct that respresents the current local time for the user

    // Print the current time
    ShowTime(timeinfo); // Calls the ShowTime() function with timeinfo as the patrameters

    while (true) { // Begins a loop that will continue to run unless the number 4 is pressed
        
        cout << endl;
        cout << endl;
        ClockMenu(); // Calls the clock menu for the first time
        cout << endl;

        int userSelection; // Declares variable for user input
        cin >> userSelection; // Request first user input
        cout << endl;
        cout << endl;

        switch (userSelection) { // Declares a switch case that will direct users request to certain actions
            case 1:
                addHour(timeinfo); // if 1 is chosen timeinfo pointer directs tm struct "tm_hour" to increase the pulled time by one hour
                break; //ends current iteration any time break is hit and restarts another unless
            case 2:
                addMinute(timeinfo); //if 2 is chosen timeinfo pointer directs tm struct "tm_min" to increase the pulled time by one minute
                break;
            case 3:
                addSecond(timeinfo); //if 3 is chosen timeinfo pointer directs tm struct "tm_sec" to increase the pulled time by one second
                break;
            case 4: // Choosing number 4 will end the program after printing a farewell
                cout << "Thank you for using our time clocks today.  Goodbye!" << endl;
                cout << endl;
                return 0;
            default: // this code will run if a number or character is chosen which is not in the switch case
                cout << "Invalid number selection, please choose a valid number 1-4." << endl;
                cout << endl;
                break;
        }

        // Print the updated time depending on which user choice was selected during the user input.  Unless it was a four, this loops back to ClockMenu() and user input
        ShowTime(timeinfo);
    }

}