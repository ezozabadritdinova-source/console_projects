#include <iostream> //E'zoza Badritdinova U2510278 23/10/2025
using namespace std;

void convertTime(int totalSeconds);
void convert(double amount, double rate);
void showMenu();
double total(double price, double quantity, double discount);
void displayResult(double totalBeforeDiscount, double totalDiscountValue, double finalAmount);


int main() {
    cout << "--- Task 1: Time Conversion ---" << endl;
    int inputSeconds;
    do {
        cout << "Please enter the total number of seconds: ";
        cin >> inputSeconds;
        if (inputSeconds < 0) {
            cout << "Invalid input. Please enter a non-negative number." << endl;
        }
    } while (inputSeconds < 0);
    convertTime(inputSeconds);

    cout << "--- Task 2: Currency Converter ---" << endl;
    double baseAmount, exchangeRate;
    char userChoice;
    do {
        cout << "Enter the amount to convert: ";
        cin >> baseAmount;
        cout << "Enter the exchange rate: ";
        cin >> exchangeRate;
        convert(baseAmount, exchangeRate);

        cout << "Perform another conversion? (y/n): ";
        cin >> userChoice;
    } while (userChoice == 'y' || userChoice == 'Y');
    cout << "Thank you! The program has ended." << endl;

    cout << "--- Task 3: Billing System ---" << endl;
    int menuSelection;
    double grandTotal = 0.0, totalDiscount = 0.0, finalBill = 0.0;
    bool hasItems = false;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> menuSelection;

        switch (menuSelection) {
            case 1: {
                hasItems = true;
                char addAnotherItem;
                do {
                    double unitPrice, quantity, itemDiscount;
                    cout << "Unit price: ";
                    cin >> unitPrice;
                    cout << "Quantity: ";
                    cin >> quantity;
                    cout << "Item discount (% 0-100): ";
                    cin >> itemDiscount;

                    double subTotal = unitPrice * quantity;
                    double itemFinalCost = total(unitPrice, quantity, itemDiscount);
                    double discountValue = subTotal - itemFinalCost;

                    grandTotal += subTotal;
                    totalDiscount += discountValue;
                    finalBill += itemFinalCost;

                    cout << "Added -> total=" << subTotal << ", discount=" << discountValue
                         << ", Total after discount=" << itemFinalCost << endl;

                    cout << "Add another item? (y/n): ";
                    cin >> addAnotherItem;
                } while (addAnotherItem == 'y' || addAnotherItem == 'Y');
                break;
            }
            case 2:
                if (!hasItems) {
                    cout << "No items available!" << endl;
                } else {
                    displayResult(grandTotal, totalDiscount, finalBill);
                }
                break;
            case 3:
                cout << "Thank you! Program ended." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (menuSelection != 3);

    return 0;
}

void convertTime(int totalSeconds) {
    int hours = totalSeconds / 3600;
    int remseconds = totalSeconds % 3600;
    int minutes = remseconds / 60;
    int seconds = remseconds % 60;
    cout << hours << " hour(s), " << minutes << " minute(s), " << seconds << " second(s)" << endl;
}

void convert(double amount, double rate) {
    double convertedAmount = amount * rate;
    cout << "Converted amount: " << convertedAmount << endl;
}

void showMenu() {
    cout << endl;
    cout << "===== BILLING SYSTEM =====" << endl;
    cout << "1. Add items" << endl;
    cout << "2. Show totals" << endl;
    cout << "3. Exit" << endl;
}

double total(double price, double quantity, double discount) {
    double sTotal = price * quantity;
    double discountAmount = sTotal * (discount / 100.0);
    double totalToPay = sTotal - discountAmount;
    return totalToPay;
}

void displayResult(double totalBeforeDiscount, double totalDiscountValue, double finalAmount) {
    cout << endl;
    cout << "Total (before discounts): " << totalBeforeDiscount << endl;
    cout << "Total discounts         : " << totalDiscountValue << endl;
    cout << "Total (to pay)          : " << finalAmount << endl;