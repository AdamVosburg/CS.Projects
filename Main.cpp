#include <iostream> // Including the standard library
#include <limits> //Included header that will name a certain limit of characters to be ignored later in the main
#include "GroceryTrackingApp.h" // Including the code from the GroceryTrackingApp.h and .cpp files
#include "GroceryTrackingApp.cpp"

using namespace std; // Declares use of the standard namespace

// Simple function to print a menu face for theapplication
void printMenu() {

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@       1. Enter an item and its frequency within the database       @\n";
    cout << "@     2. Get the frequency of all items located in the database      @\n";
    cout << "@   3. Print a histogram of item frequencies within the database     @\n";
    cout << "@           4. Exit the Chada Grocery Item Tracking App              @\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    cout << endl;
}

    
/*
* The following function allows the user to input items into the grocery
* tracking app.  It will store a string or even a line variable for name by taking an input,
* add it to the tracker, and print an updated frequency of the item.  It will also
* track for unwanted integers so user cannot mess up frequency counts.
*/
void enterItem(GroceryTracker& tracker) {
    string input; 
    cout << "Enter the name of the item: ";
    getline(cin, input); // Get the entire line of input, including spaces
    
    /*
    * This try/catch will try and convert last word of line to a int
    * as a means to prevent user from entering their own frequency.  If so, an error message
    * will be returned.
    * */
    string lastWord = input.substr(input.rfind(' ') + 1);
    try {
        std::stoi(lastWord);
        cerr << "Error: Please only enter the item name without a related frequency. The program already calculates these." << endl;
        return;
    } catch (const std::invalid_argument& e) { //
        
    }

    tracker.addItem(GroceryItem(input)); // Add the item to the tracker
    cout << "The updated frequency of " << input << ": " << tracker.getItemFrequency(GroceryItem(input)) << endl;
}


/*
* The following function will print an int for the frequency of each item in the data file.
* It does so by reading the mapped pairs.  The for loop will search through each line of 
* the map and print the first of the pair, item an then the second part, frequency.
*/
void printFrequencies(GroceryTracker& tracker) {
    map<string, int> frequencies = tracker.getAllItemsFrequency(); // Get all item frequencies
    // Loop through the map and print each item and its frequency
    for (const auto& pair : frequencies) {
        string trimmedItemName = pair.first;
        trimmedItemName.erase(trimmedItemName.find_last_not_of(' ') + 1);  // Trim trailing white spaces
        cout << trimmedItemName << ": " << pair.second << endl;
    }
}

/* 
* The following code will call the previously created (in .cpp file) printHistogram method.
* This prints out very similar to the previous code bloc but returns an asterisk for
* every iteration of frequency rather than an int.  Ina ddition, it assigns the first pair which
is a string and trims any unneccesary whitespace providing a cleaner output for histoggram.
*/
 
void printHistogram(GroceryTracker& tracker) {
    for (const auto& pair : tracker.getAllItemsFrequency()) {
        string trimmedItemName = pair.first;
        trimmedItemName.erase(trimmedItemName.find_last_not_of(' ') + 1);  // Trim trailing white spaces

        cout << trimmedItemName << ": ";
        for (int i = 0; i < pair.second; ++i) {
            cout << '*';
        }
        cout << '\n';
    }
}

// Declaring the main function of the program
int main() {
    GroceryTracker tracker; // This line creates a new GroceryTracker object
    // Load data from the initial input file on the file path saved to my computer
     tracker.loadFromFile("frequency.dat");

    cout << endl;
    cout << endl;

    // This code prints a standard header of the  upon first entering the program
    cout << "====================================\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "  Chada Corner Grocer Tracking App\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "====================================\n";

    cout << endl;
    cout << endl;


    /*
    * The following code block is a while loop that first prints the menu, names an int option
    * for user selection storage and includes an error catch for no valid inputs.  It utilizes ignore
    * to help idetify inputs that arent valid and returns an exception message.  If a valid number is chosen
    * further statements direct how the program will operate.
    * */
    while (true) {
        printMenu(); // Calls the print menu option defined earlier

        int option; // Variable to store the user's menu option choice
        
        if (!(cin >> option)) { // If statement to catch invalid menu inputs
            cin.clear();  // clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore leftover '\n'
            cout << "These inputs are not valid. Please enter a number from 1 to 4." << endl;
            continue;
        }
        cin.ignore(1000, '\n'); // Ignore any leftover characters in the input buffer

        // Process the user's menu choice
        if (option == 1) {
            enterItem(tracker); // Allow the user to enter an item and it will print the frequency as well
            cout << endl;
        } else if (option == 2) {
            printFrequencies(tracker); // Print the frequency of all items as defined earlier
            cout << endl;
        } else if (option == 3) {
            printHistogram(tracker); // Print a histogram of item frequencies as defined earlier
            cout << endl;
        } else if (option == 4) {
            // Simple exit message before ending prorgams
            cout << "Thank you for using the Chada Grocery Item Tracking Application.  Have a wonderful day!" << endl;
            break;
        }

        // Save the current state of the database to a file
        tracker.saveToFile("frequency.dat");
    }

    return 0; // End of main function
}
