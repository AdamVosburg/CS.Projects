#ifndef AGBANKINGAPP_H //Header used as a guard to prevent multplie insatmces of same header
#define AGBANKINGAPP_H

/* 
*  The code featured here will declare the AGBankingApp class, which represents an application 
*  for calculating and displaying banking reports.  It creates the functions utilized in the
*  AGBankingApp.cpp files to allow the prorgam to function as it should.
*/
class AGBankingApp {
public: // Made public so it can be directly accessed by AGBankingApp.cpp and Main.cpp

    // Initializes a Constructor of the AGBankingApp class with the provided variables needed later.
    AGBankingApp(double initialInvestment, double annualInterestRate, int yearsCompounded);

    // Decalres a function needed to calculate interest rates
    double calculateInterest(double totalInvestment, double monthlyInterestRate) const;

    // Declares a function which will display all the manipulated user values
    void displayYearEndReportWithoutPayments() const;

    // Declares a function which will display all manipluated values WITH monthly payment
    void displayYearEndReportWithPayments(double monthlyDeposit) const;

private: //These variables are set to private in order to maintain integrity outside of class usage
    double initialInvestment;
    double annualInterestRate;
    int yearsCompounded;
};

#endif // AGBANKINGAPP_H helps to close the guard defined earlier
