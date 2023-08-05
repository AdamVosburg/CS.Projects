#include "AGBankingApp.h" // Declaring the .h file header to define the method actions
#include <iostream> // Declares generic input output header
#include <iomanip> //Declares header to manipulate user values
#include <cmath> //Declares a header to utilize math functions within the .cpp program

using namespace std; //Standard fucntion to utilize cin and cout without std:: format

/*
*  The followng code block creates a constructor which defines the varaibles needed for
*  creating an object of the AGBankingApp.  It will utilize initialInvestment, annualInterestRate
*  and yearsCompunded and store these values in the object.
*/
AGBankingApp::AGBankingApp(double initialInvestment, double annualInterestRate, int yearsCompounded)
    : initialInvestment(initialInvestment), annualInterestRate(annualInterestRate), yearsCompounded(yearsCompounded) {}

/*
*  The followng code block creates a constructor which caluclates the varaibles needed for
*  creating an object of the AGBankingApp.  It will utilize totalInvestment and monthlyInterestRate
*  to caluclate what the different interests rates are.  It will then be called by later functions
*  to provide amounts for further caluclations.
*/
double AGBankingApp::calculateInterest(double totalInvestment, double monthlyInterestRate) const {
    return totalInvestment * monthlyInterestRate;
}

/*
*  The followng code block creates a function which outputs a small header and calculations which
*  will output values dependent on user inputs.  The variables here define variable amounts for 
*  the contstuctor featured above which is called further into the code block.  It will then be 
*  called in the main to display final results.
*/
void AGBankingApp::displayYearEndReportWithoutPayments() const {
    double monthlyInterestRate = annualInterestRate / 100.0 / 12;
    double totalInvestment = initialInvestment;
    double interestEarned, yearEndBalance;

    // Output header mentioned above
    cout << "Year\t\tYear End Balance\tInterest Earned During Year" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    // For loop that cotinue until user input for Years Compounded is reached and increments up
    for (int year = 1; year <= yearsCompounded; year++) {
        interestEarned = 0.0; // Default value
        for (int month = 1; month <= 12; month++) { // Embedded for loop that examines each month in 1 year
            // Calculate interest on a monthly basis
            double monthlyInterest = calculateInterest(totalInvestment, monthlyInterestRate);

            // This code will increment each monthly interest total until a full year is reached (SUM)
            interestEarned += monthlyInterest;

            // Update totalInvestment each time a month is looped through
            totalInvestment += monthlyInterest;
        }

        // This will calclate the final sum for each year before beginning entore loop again
        yearEndBalance = totalInvestment;

        /* This code will display the values when all the loops have been finished according to parameters.  
        *  setw is used here to appropriately line up value totals in report.  Set precision is used to ensure 
        * no doubles show large numbers by setting decimal places to 2.
        * */
        cout << setw(4) << year << "\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t$" << interestEarned << endl;
    }
}

/*
*  Similar to the code featured above, this code block will perform the same actions as the
*  code seen prior but it will take monthly payments in addition to the other varaibles and increment
*  those amounts into the totals.  The output will appear the same but will reflect additional monetary
*  value.
*/
void AGBankingApp::displayYearEndReportWithPayments(double monthlyDeposit) const {
    double monthlyInterestRate = annualInterestRate / 100.0 / 12;
    double totalInvestment = initialInvestment;
    double interestEarned, yearEndBalance;

    // Display data for each year but with upated total
    cout << "Year\t\tYear End Balance\tInterest Earned During Year" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int year = 1; year <= yearsCompounded; year++) {
        interestEarned = 0.0;
        for (int month = 1; month <= 12; month++) {
            // Calculate interest as before
            double monthlyInterest = calculateInterest(totalInvestment, monthlyInterestRate);

            // Add interest to the year's total
            interestEarned += monthlyInterest;

            // Update totalInvestment for the next month
            totalInvestment += monthlyInterest;

            // This code will add the monthly payments into total investment
            totalInvestment += monthlyDeposit;
        }

        // Calculate year-end balance
        yearEndBalance = totalInvestment;

        // Display data for the current year like the previous output of the prior function
        cout << setw(4) << year << "\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t$" << interestEarned << endl;
    }
}
