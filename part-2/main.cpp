// main.cpp
#include <iostream>
#include <string>
#include "Host.h"
#include "Order.h"
#include "Patron.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"

using namespace std;

int main() {
    Host host;
    string patronName;
    cout << "Welcome to Cafe++!" << endl;
    cout << "Please enter your name: ";
    getline(cin, patronName);
    Patron patron(patronName);
    Order order(patron);

    int choice;
    do {
        cout << "\n===== Cafe++ Menu =====\n";
        cout << "1: Add Food Item\n";
        cout << "2: Add Drink Item\n";
        cout << "3: Place Order\n";
        cout << "0: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int foodChoice;
                cout << "\n===== Food Items =====\n";
                cout << "1: Candy Bar\n";
                cout << "2: Bag of Chips\n";
                cout << "Enter your choice: ";
                cin >> foodChoice;

                switch (foodChoice) {
                    case 1:
                        order.addFoodItem(Food("Candy Bar"));
                        cout << "Candy Bar added to your order.\n";
                        break;
                    case 2:
                        order.addFoodItem(Food("Bag of Chips"));
                        cout << "Bag of Chips added to your order.\n";
                        break;
                    default:
                        cout << "Invalid choice. Food item not added.\n";
                        break;
                }
                break;
            }
            case 2: {
                int drinkChoice;
                cout << "\n===== Drink Items =====\n";
                cout << "1: Black Coffee\n";
                cout << "2: White Coffee\n";
                cout << "Enter your choice: ";
                cin >> drinkChoice;

                int sugarAmount;
                do {
                    cout << "Enter the number of sugars: ";
                    cin >> sugarAmount;
                    if (sugarAmount < 0) {
                        cout << "Invalid sugar amount. Please try again.\n";
                    }
                } while (sugarAmount < 0);

                switch (drinkChoice) {
                    case 1:
                        order.addDrinkItem(BlackCoffee(sugarAmount));
                        cout << "Black Coffee with " << sugarAmount << " sugar(s) added to your order.\n";
                        break;
                    case 2:
                        order.addDrinkItem(WhiteCoffee(sugarAmount));
                        cout << "White Coffee with " << sugarAmount << " sugar(s) added to your order.\n";
                        break;
                    default:
                        cout << "Invalid choice. Drink item not added.\n";
                        break;
                }
                break;
            }
            case 3: {
                if (order.isEmpty()) {
                    cout << "\nYour order is empty.\nPlease add at least one item before placing an order.\n";
                } else {
                    cout << "\n===== Order Summary =====\n";
                    order.displayOrder();
                    cout << "\nDo you want to proceed with placing the order? (Y/N): ";
                    char confirmation;
                    cin >> confirmation;
                    if (confirmation == 'Y' || confirmation == 'y') {
                        patron.placeOrder(unique_ptr<Order>(new Order(patron)));
                        host.takeOrder(patron);
                    } else {
                        cout << "Order cancelled.\n";
                    }
                }
                break;
            }
            case 0:
                cout << "\nThank you for visiting Cafe++! Have a great day!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}