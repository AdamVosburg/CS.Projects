#include <fstream>  // Including a library to access files
#include <iostream>  // Including standard library
#include "GroceryTrackingApp.h"  // Includes this to utilize the class and methods available in GroceryTrackingApp.h
#include <sstream> // Includes stringstream library as the .dat files may contain items with multiple words
#include <string> // Including standard string library as string variable will be needed

/*
* Creates the constructor for the grocert tracker.  It has empty brackets as 
* the map for GroceryTracker does not need to be initialized.
*/
GroceryTracker::GroceryTracker() {}

/*
* Creates the destructor for the grocery tracker.  It ensures that once the Tracker
* has finalized its actions, it does not go out of scope.
*/
GroceryTracker::~GroceryTracker() {}

/* 
* Method to add an item to the 'items' map. It will increment any value associated 
* with an item name.  If a new value is entered, it is added to the map with a value of 1.
* In addition, if an item already exists, it will iterate the value of frequenct up by each input
* of the item name.
*/
void GroceryTracker::addItem(const GroceryItem& item) {
    items[item.getName()]++;
}

/* 
* Method to gets the frequency of an item.  If the item exists, it returns the corresponding
* value, otherwise it returns a 0.  By utilizing "auto", C++ will infer the variables, in this case 
* a string.  The found item name is then passed through an if statement searching for a (string,int)
* pair.  If the item is not found, it will return a zero.  If an item is there, it will return the
* second part of the pair (int) for its frequency.  It does so by utilizing a pointer.
*/
int GroceryTracker::getItemFrequency(const GroceryItem& item) const {
    auto it = items.find(item.getName());
    if (it != items.end()) {
        return it->second;
    } else {
        return 0;
    }
}

/*
* This method will bascially return te entire item map for the program.  Every item and
* their corresponding frequencies will be returned with this.
*/
map<string, int> GroceryTracker::getAllItemsFrequency() const {
    return items;
}

/*
* This method will return the same thing that the previous method does but instead
* of returning the int for the frequency, it returns an asterisk for every iteration of
* the item name.
*/
void GroceryTracker::printHistogram() const {
    for (const auto& pair : items) {
        cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            cout << '*';
        }
        cout << '\n';
    }
}

/*
* The following method will search for a file from a designated path and attempt to
* open the file.  If successful, it will read the data up until it locates an int.  It then separates the 
* string/int into the item map.  If unsuccessful,it will return an error message.  Once the method 
* has finished reading/saving, It will close the file.
*/

void GroceryTracker::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open the necessary .dat file: " << filename << endl;
        return;
    }
    string line; 
    while (getline(inFile, line)) {
        int i = line.size() - 1;
        while (i >= 0 && isdigit(line[i])) {
            --i;
        }
        string itemName = line.substr(0, i + 1);  // Gets the item name which includes everything up to the int frequency
        int frequency = stoi(line.substr(i + 1));  // Gets the frequency
        for(int j = 0; j < frequency; j++) {
            this->addItem(GroceryItem(itemName)); 
        }
    }
    inFile.close(); 
}


/*
* Similar to the method above, this file will write all of the data into
* a designated file/path from the item map.  It has similar features to output an error message if 
* the file is unreachable or if the data cannot be written into frequency.dat. This will also
* save the data in pairs separated by a single whitespace.
*/
void GroceryTracker::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Unable to open the necessary .dat file: " << filename << endl;
        return;
    }

    // Loop through the items map and write each item and its frequency to the file
    for (const auto& pair : items) {
        outFile << pair.first << ' ' << pair.second << '\n';
    }

    outFile.close();
}
