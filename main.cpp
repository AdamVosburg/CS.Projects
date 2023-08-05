#include <iostream> // Declaring the standard input and output header
#include <iomanip> // Declares a header which allows manipulation of the input and output values
#include "AGBankingApp.h" // Declares header to allow class and member use of the AGBankingApp file
#include "AGBankingApp.cpp" // Declares header to allow use of defining characteristicws of .cpp file and its member functions

using namespace std; //Allows the use of cout and cin functions

/*
* The following function takes the variables intialInvestment, monthlyDeposit
* annualInterestRate, and years compounded and outputs a "menu face" which is called 
* periodically throughout the prorgam.  This is a visual component which displays blank and user input values.
*/
void AirGeadBankMenu(double initialInvestment, double monthlyDeposit, double annualInterestRate, int yearsCompounded) {
    cout << endl;
    cout << "***********************************************\n";
    cout << "*************   User Data Input   *************\n";
    cout << " Initial Investment Amount:   $" << initialInvestment << "\n";
    cout << " Monthly Deposit:             $" << monthlyDeposit << "\n";
    cout << " Annual Interest:             " << annualInterestRate << "%\n";
    cout << " Years to Compound:           " << yearsCompounded << " years\n";
    cout << "***********************************************\n";
}

// Declares the initial main function through which the prorgam will run
int main() {

    // The following is a generic greeting for all users
    cout << endl;
    cout << "Welcome to the Airgead Banking Application!" << endl;
    cout << "This program will give you a plan to invest wisely." << endl;
    cout << "Please view our menu and enter your initial investment values." << endl;
    cout << "This program will show you how much interest you can earn WITH and WITHOUT additional monthly payments" << endl;
    cout << endl;

    // Initializing the diffferent variables with default values prior to user input
    double initialInvestment = 0.0;
    double monthlyDeposit = 0.0;
    double annualInterestRate = 0.0;
    int yearsCompounded = 0;


    /* 
    * The code below converts inputs to strings which will later be converted to doubles. This will catch 
    * "quit" characters prior to calculations and terminte the prorgam.  If q or Q is not entered, later code
    * displayed will convert the strings to doubles for caluclated interest
    */
    string input; 

    /*
    *  This begins an indefinite loop that will continue to call the bank face menu,
    *  request user inputs,caluculate interest rates, output values into the menu and displays two reports with 
    *  and without additional monthly payments.  Further breakdown is featured below.
    *  */
    do {
        AirGeadBankMenu(initialInvestment, monthlyDeposit, annualInterestRate, yearsCompounded); // Display the menu with default values first

        cout << endl;

        // Outputs text requesting user input for Initial Investment amount
        cout << "Initial Investment Amount (enter 'q' to quit): $";
        cin >> input; // User input
        if (input == "q" || input == "Q") { // If statment that will quit program if specified character value is met
            cout << "\nThank you for using the AirGead Banking Application. Have a wonderful day!" << endl;
            cout << endl;
            break;
        }
        initialInvestment = stod(input); // First instance of variable being converted back to a double for calculations

        // Outputs text requesting user input for Annual Interest amount
        cout << "Annual Interest Rate (%) (enter 'q' to quit): ";
        cin >> input;
        if (input == "q" || input == "Q") { // If statement for break if necessary
            cout << "\nThank you for using the AirGead Banking Application. Have a wonderful day!" << endl;
            cout << endl;
            break;
        }
        annualInterestRate = stod(input); // Second instance of variable being converted back to a double for calculations

        // Outputs text requesting user input for Number of years to compound interest amount
        cout << "Years to compound interest (enter 'q' to quit): ";
        cin >> input;
        if (input == "q" || input == "Q") {
            cout << "\nThank you for using the AirGead Banking Application. Have a wonderful day!" << endl;
            cout << endl;
            break;
        }
        yearsCompounded = stoi(input); // Third instance of variable being converted back to a double for calculations


        cin.ignore(); // Ignore any remaining characters in the input buffer

        // Calls the menu to now display again with the userInputs that are included in the parameters
        AirGeadBankMenu(initialInvestment, monthlyDeposit, annualInterestRate, yearsCompounded); 

        //Generic message awaiting any user key to continue or quit
        cout << endl;
        cout << "\nPress any key to continue or enter 'q' to quit..." << endl;
        cin.ignore(); 
        cin.get(); // Wait for user input

        /*
        * The following function from the AGBankingApp will create an object to take the input values
        * (which have been converted back to doubles) and store them in the variables listed in the parameters.
        */
        AGBankingApp banking(initialInvestment, annualInterestRate, yearsCompounded);

        cout << endl; // Extra endline added for ease of viewing

        /*
        *  The following code will output a header seen below as well as print a report for the stored values 
        *  calculated in the code above WITHOUT monthly payments.  It does so by creating an object and calling the 
        *  displayYearEndReportWithoutPayments class.  The remainder of output can be found in AGBankingApp.cpp.
        *  */
        cout << "*********************************************************************" << endl;
        cout << "       Balance and Interest Without Additional Monthly Payments" << endl;
        cout << "*********************************************************************" << endl;
        banking.displayYearEndReportWithoutPayments();
        cout << "*********************************************************************" << endl;
        cout << endl;

        // Requests user to input a value for monthly payments
        cout << "Monthly Deposit (enter 'q' to quit): $";
        cin >> input;
        if (input == "q" || input == "Q") {
            cout << "\nThank you for using the AirGead Banking Application. Have a wonderful day!" << endl;
            cout << endl;
            break;
        }
        monthlyDeposit = stod(input); // Final instance of converting prior string to double in order to catch quit characters

        cin.ignore(); 

        // Calls banking menu again with updated user value for monthly payments
        AirGeadBankMenu(initialInvestment, monthlyDeposit, annualInterestRate, yearsCompounded); 

        cout << "\nPress any key to continue or enter 'q' to quit..." << endl;
        cin.ignore(); 
        cin.get(); 

        /*
        *  The following code will output a header seen below as well as print a report for the stored values 
        *  calculated in the code above WITH monthly payments.  It does so by creating an object and calling the 
        *  displayYearEndReportWithPayments class.  The remainder of output can be found in AGBankingApp.cpp.
        *  */
        cout << "*********************************************************************" << endl;
        cout << "         Balance and Interest With Additional Monthly Payments" << endl;
        cout << "*********************************************************************" << endl;
        banking.displayYearEndReportWithPayments(monthlyDeposit);
        cout << "*********************************************************************" << endl;
        cout << endl;

    } while (true); // Loop will continue until the user enters 'q' or 'Q'

    return 0;
} 
