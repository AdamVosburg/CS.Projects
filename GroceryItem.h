#ifndef GROCERYITEM_H // Declare headers to safe guard the following program from calling headers multiple times
#define GROCERYITEM_H // Defines the following application

 
#include <string> // Declaring file to include string library to utilize std:: below

// Declare the GroceryItem class so it can be called later to generate items per user input
class GroceryItem {
private:
    // Declare a private variable string to hold the name of the grocery item
    std::string name;

public:
    /* 
    *  Declare a public constructor that takes a string for name of an item
    *  and initializes the name member variable with the users input argument.
    *  By using the const, the constructor cannot modify the string and the & is used as 
    *  a reference similar to a pointer
    */
    GroceryItem(const std::string& name) : name(name) {}

    /*
    *  Declare a public function accessor that takes no parameters and returns a string.
    *  Again, const was used to protect the string 'name' from being modified.  Returns the member
    *  variable 'name'
    */
    std::string getName() const {
        return name;
    }
};


#endif // This indicates the end of processing the code for GroceryItem_H
