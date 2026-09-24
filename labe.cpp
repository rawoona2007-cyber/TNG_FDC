// =========================================================
// Touch 'n Go eWallet Simulator
// A simple beginner-level C++ console program
// University Group Project
// =========================================================

#include <iostream>
#include <iomanip>   // for setprecision (RM formatting)
#include <vector>
#include <string>
using namespace std;

// ---------------------------------------------------------
// Global variables
// (Simple approach for beginner-level project - no classes)
// ---------------------------------------------------------
double balance = 0.00;              // Starting sample balance = RM0.00
vector<string> transactionHistory;    // Stores transaction records as text

// ---------------------------------------------------------
// Function: checkBalance()
// Displays the current wallet balance
// ---------------------------------------------------------
void checkBalance() {
    cout << fixed << setprecision(2); // Always show 3 decimal places for RM
    cout << "\nYour current balance is: RM" << balance << endl;
}

// ---------------------------------------------------------
// Function: topUp()
// Allows the user to add money into the wallet
// ---------------------------------------------------------
void topUp() {
    double amount;

    cout << "\nEnter amount to top up: RM";
    cin >> amount;

    // Validation: prevent zero or negative top up
    if (amount <= 0) {
        cout << "Invalid amount! Top up must be more than RM0.00.\n";
        return; // exit the function early
    }

    balance += amount; // Add amount to balance

    cout << fixed << setprecision(2);
    cout << "Top up successful! New balance: RM" << balance << endl;

    // Save this transaction into history
    transactionHistory.push_back("Top Up: +RM" + to_string(amount));
}

// ---------------------------------------------------------
// Function: makePayment()
// Allows the user to make a simple payment (e.g. shopping)
// ---------------------------------------------------------
void makePayment() {
    double amount;

    cout << "\nEnter payment amount: RM";
    cin >> amount;

    // Validation: prevent zero or negative payment
    if (amount <= 0) {
        cout << "Invalid amount! Payment must be more than RM0.00.\n";
        return;
    }

    // Check if balance is enough before paying
    if (amount > balance) {
        cout << "Payment failed! Insufficient balance.\n";
        cout << fixed << setprecision(2);
        cout << "Your current balance is only RM" << balance << endl;
        return;
    }

    balance -= amount; // Deduct payment from balance

    cout << fixed << setprecision(2);
    cout << "Payment successful! New balance: RM" << balance << endl;

    transactionHistory.push_back("Payment: -RM" + to_string(amount));
}

// ---------------------------------------------------------
// Function: payToll()
// Allows the user to pay toll charges
// (Similar logic to makePayment, but treated separately
//  since Touch 'n Go is widely used for toll payments)
// ---------------------------------------------------------
void payToll() {
    double tollAmount;

    cout << "\nEnter toll amount: RM";
    cin >> tollAmount;

    if (tollAmount <= 0) {
        cout << "Invalid amount! Toll amount must be more than RM0.00.\n";
        return;
    }

    if (tollAmount > balance) {
        cout << "Toll payment failed! Insufficient balance.\n";
        cout << fixed << setprecision(2);
        cout << "Your current balance is only RM" << balance << endl;
        return;
    }

    balance -= tollAmount;

    cout << fixed << setprecision(2);
    cout << "Toll payment successful! New balance: RM" << balance << endl;

    transactionHistory.push_back("Toll Payment: -RM" + to_string(tollAmount));
}

// ---------------------------------------------------------
// Function: showHistory()
// Displays all past transactions stored in the vector
// ---------------------------------------------------------
void showHistory() {
    cout << "\n----- Transaction History -----\n";

    // If no transactions yet
    if (transactionHistory.empty()) {
        cout << "No transactions yet.\n";
        return;
    }

    // Loop through the vector and print each transaction
    for (int i = 0; i < transactionHistory.size(); i++) {
        cout << i + 1 << ". " << transactionHistory[i] << endl;
    }
}

// ---------------------------------------------------------
// Function: showMenu()
// Displays the main menu options
// ---------------------------------------------------------
void showMenu() {
    cout << "\n========================================\n";
    cout << "     TOUCH 'N GO eWALLET SIMULATOR\n";
    cout << "========================================\n";
    cout << "1. Check Balance\n";
    cout << "2. Top Up Wallet\n";
    cout << "3. Make Payment\n";
    cout << "4. Pay Toll\n";
    cout << "5. View Transaction History\n";
    cout << "6. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

// ---------------------------------------------------------
// Main function
// Controls the program flow using a loop and switch statement
// ---------------------------------------------------------
int main() {
    int choice;

    cout << "Welcome to the Touch 'n Go eWallet Simulator!\n";

    // Loop keeps showing the menu until user chooses Exit (6)
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                topUp();
                break;
            case 3:
                makePayment();
                break;
            case 4:
                payToll();
                break;
            case 5:
                showHistory();
                break;
            case 6:
                cout << "\nThank you for using Touch 'n Go eWallet Simulator!\n";
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
        }

    } while (choice != 6); // Repeat until user selects Exit

    return 0;
}
