#ifndef GROCERYTRACKINGAPP_H // Opening a new header to prevent reoccurence of code calling
#define GROCERYTRACKINGAPP_H // Define GROCERYTRACKINGAPP_H, so that if the compiler encounters this header again,it cant be included more than once.

#include <map>  // Include a C++ library that maps items and includes their frequencies
#include <string>  // Include a library to manipulate strings within the code
#include "GroceryItem.h"  // Utilizers the previously created header so Item names can be accessed

// Declare the use of the namespace library to avoid using std:: before every object like cin/cout
using namespace std;

/*
*  Creating a class which can track Grocery Items.  This will conect string names
*  to the frequencies within the file.  Inside it will also name different methods 
*  to add items, get the frequencies of single and all items, and print the histograms rather than 
*  frequencies.  In addition, methods are named to load and save a file used to extrapolate data
* into the database.
*/

class GroceryTracker {
private:
    map<string, int> items;  // A map that connects item names to their frequenices. 

public:
    GroceryTracker();  // The constructor of the GroceryTracker class
    ~GroceryTracker();  // The destructor of the GroceryTracker class

    void addItem(const GroceryItem& item); // This method adds an item to the items map. This uses a Grocery Item object

    /*
    * This method gets the frequency of an item from the items map. Also uses a Grocery Item 
    * object and returns int for its occurences.
    */
    int getItemFrequency(const GroceryItem& item) const;

    /* 
    * This method will make a  map of all item frequencies. Returns a digital map where the keys are item names 
    * and the values are frequencies.
    */
    map<string, int> getAllItemsFrequency() const;

    void printHistogram() const; // This method will print a map of the histrogram

    /* 
    * This method loads item frequencies from a file that has a named path (CS-210....). Takes 
    *  the file name as an argument. This will import the data from a txt file into the mapping.
    */
    void loadFromFile(const string& filename);

    /* 
    * This method saves item frequencies into a dat file used later. This will export the data from
    * the program into a file named frequencies.dat.
    */
    void saveToFile(const string& filename);
};


#endif // Finishes processing the CroceryTrackingApp_H file
