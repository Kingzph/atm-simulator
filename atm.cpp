#include <iostream>
#include <string>

int main() {
    while (true) {  // Outer loop to return to welcome screen
        // Welcome Screen
        std::cout << "Welcome to C++ Bank!\n";

        int attempt = 0;
        std::string four_digit_pin_str;
        int four_digit_pin_int;

        while (attempt < 3) {
             std::cout << "Please enter your 4-digit PIN: ";
             std::getline(std::cin, four_digit_pin_str);
             four_digit_pin_int = std::stoi(four_digit_pin_str); 

             if (four_digit_pin_int == 1234) {
                std::cout << "Access granted!\n";
                break;
             } else {
                attempt++;
                if (attempt < 3) {
                std:: cout << "Wrong password! Please try again: \n";
                }
             }
       
            if (attempt == 3) {
                std::cout << "Too many failed attempts, exiting system!\n";
                return 0;
            }
        }

        // User balance (can be updated)
        float user_balance = 150.5;

        while (true) {  // Inner loop for ATM menu
            std::cout << "\nMenu:\n";
            std::cout << "1. Check balance\n";
            std::cout << "2. Deposit money\n";
            std::cout << "3. Withdraw money\n";
            std::cout << "4. Exit\n";

            int user_choices;
            std::cout << "Enter your choice: ";
            std::cin >> user_choices;

            switch (user_choices) {
                case 1: {
                    std::cout << "Your balance is: " << user_balance << "\n";
                    break;
                }
                case 2: {
                    float user_deposit;
                    std::cout << "Enter the amount to deposit: ";
                    std::cin >> user_deposit;

                    if (user_deposit > 0) {
                        user_balance += user_deposit;
                        std::cout << "Deposit successful. You now have " << user_balance << "\n";
                    } else {
                        std::cout << "Invalid deposit amount! Please try again.\n";
                    }
                    break;
                }
                case 3: {
                    float user_withdraw;
                    std::cout << "Enter the amount to withdraw: ";
                    std::cin >> user_withdraw;

                    if (user_withdraw <= 0) {
                        std::cout << "Invalid withdrawal amount!\n";
                    } else if (user_withdraw > user_balance) {
                        std::cout << "Insufficient balance!\n";
                    } else {
                        user_balance -= user_withdraw;
                        std::cout << "Withdrawal successful. You now have " << user_balance << "\n";
                    }
                    break;
                }
                case 4: {
                    char user_y_n;
                    std::cout << "Are you sure you want to exit ATM (y/n)? ";
                    std::cin.ignore(); // Clear newline from previous input
                    std::cin >> user_y_n;

                    while (user_y_n != 'y' && user_y_n != 'Y' && user_y_n != 'n' && user_y_n != 'N') {
                        std::cout << "Invalid choice! Please enter 'y' or 'n': ";
                        std::cin >> user_y_n;
                    }

                    if (user_y_n == 'y' || user_y_n == 'Y') {
                        std::cout << "\nThank you for using C++ ATM. Goodbye!\n";
                        return 0; // Exit the program
                    } else {
                        char return_menu;
                        std::cout << "Do you want to return to the welcome screen? (y/n): ";
                        std::cin >> return_menu;

                        while (return_menu != 'y' && return_menu != 'Y' && return_menu != 'n' && return_menu != 'N') {
                            std::cout << "Invalid input! Please enter 'y' or 'n': ";
                            std::cin >> return_menu;
                        }

                        if (return_menu == 'y' || return_menu == 'Y') {
                            std::cout << "\nReturning to welcome screen...\n\n";
                            std::cin.ignore(); // Clear input buffer before loop
                            break;  // Exit inner ATM menu loop
                        } else {
                            std::cout << "\nThank you for using C++ ATM. Goodbye!\n";
                            return 0;  // End entire program
                        }
                    }
                    break;
                }
                default:
                    std::cout << "Invalid choice! Please try again.\n";
                    break;
            }
        }
    }

    return 0;
}
