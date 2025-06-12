#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {  // Outer loop to return to welcome screen
        // Welcome Screen
        cout << "Welcome to C++ Bank!\n";
        string four_digit_pin_str;

        cout << "Please enter your 4-digit PIN: ";
        getline(cin, four_digit_pin_str);

        int four_digit_pin_int = stoi(four_digit_pin_str);

        if (four_digit_pin_int == 1234) {
            cout << "\nWelcome back, USER!\n";
        } else {
            cout << "\nUnknown USER and PIN!\n";
            continue; // Go back to welcome screen
        }

        // User balance (can be updated)
        float user_balance = 150.5;

        while (true) {  // Inner loop for ATM menu
            cout << "\nMenu:\n";
            cout << "1. Check balance\n";
            cout << "2. Deposit money\n";
            cout << "3. Withdraw money\n";
            cout << "4. Exit\n";

            int user_choices;
            cout << "Enter your choice: ";
            cin >> user_choices;

            switch (user_choices) {
                case 1: {
                    cout << "Your balance is: " << user_balance << "\n";
                    break;
                }
                case 2: {
                    float user_deposit;
                    cout << "Enter the amount to deposit: ";
                    cin >> user_deposit;

                    if (user_deposit > 0) {
                        user_balance += user_deposit;
                        cout << "Deposit successful. You now have " << user_balance << "\n";
                    } else {
                        cout << "Invalid deposit amount! Please try again.\n";
                    }
                    break;
                }
                case 3: {
                    float user_withdraw;
                    cout << "Enter the amount to withdraw: ";
                    cin >> user_withdraw;

                    if (user_withdraw <= 0) {
                        cout << "Invalid withdrawal amount!\n";
                    } else if (user_withdraw > user_balance) {
                        cout << "Insufficient balance!\n";
                    } else {
                        user_balance -= user_withdraw;
                        cout << "Withdrawal successful. You now have " << user_balance << "\n";
                    }
                    break;
                }
                case 4: {
                    char user_y_n;
                    cout << "Are you sure you want to exit ATM (y/n)? ";
                    cin.ignore(); // Clear newline from previous input
                    cin >> user_y_n;

                    while (user_y_n != 'y' && user_y_n != 'Y' && user_y_n != 'n' && user_y_n != 'N') {
                        cout << "Invalid choice! Please enter 'y' or 'n': ";
                        cin >> user_y_n;
                    }

                    if (user_y_n == 'y' || user_y_n == 'Y') {
                        cout << "\nThank you for using C++ ATM. Goodbye!\n";
                        return 0; //EXIT THE FUCKING PROGRAM DUMBFUCK
                    } else {
                        char return_menu;
                        cout << "Do you want to return to the welcome screen? (y/n): ";
                        cin >> return_menu;

                        while (return_menu != 'y' && return_menu != 'Y' && return_menu != 'n' && return_menu != 'N') {
                            cout << "Invalid input! Please enter 'y' or 'n': ";
                            cin >> return_menu;

                        }

                        if (return_menu == 'y' || return_menu == 'Y') {
                            cout << "\nReturning to welcome screen...\n\n";
                            cin.ignore(); // Clear input buffer before loop
                            break;  // Exit inner ATM menu loop
                        } else {
                            cout << "\nThank you for using C++ ATM. Goodbye!\n";
                            return 0;  // End entire program
                        }
                    }
                    break;
                }
                default:
                    cout << "Invalid choice! Please try again.\n";
                    break;
            }
        }
    }

    return 0;
}
