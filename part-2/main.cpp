#include <iostream>
#include <string>
#include "Host.h"
#include "Order.h"
#include "Patron.h"

int main() {
    Host host;
    std::string patronName;
    std::cout << "Welcome to Cafe++!" << std::endl;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, patronName);
    Patron patron(patronName);
    Order order(patron);

    int choice;
    do {
        std::cout << "\n===== Cafe++ Menu =====\n";
        std::cout << "1: Add Food Item\n";
        std::cout << "2: Add Drink Item\n";
        std::cout << "3: Place Order\n";
        std::cout << "0: Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int foodChoice;
                std::cout << "\n===== Food Items =====\n";
                std::cout << "1: Candy Bar\n";
                std::cout << "2: Bag of Chips\n";
                std::cout << "Enter your choice: ";
                std::cin >> foodChoice;

                switch (foodChoice) {
                    case 1:
                        order.addFoodItem("Candy Bar");
                        std::cout << "Candy Bar added to your order.\n";
                        break;
                    case 2:
                        order.addFoodItem("Bag of Chips");
                        std::cout << "Bag of Chips added to your order.\n";
                        break;
                    default:
                        std::cout << "Invalid choice. Food item not added.\n";
                        break;
                }
                break;
            }
            case 2: {
                int drinkChoice;
                std::cout << "\n===== Drink Items =====\n";
                std::cout << "1: Black Coffee\n";
                std::cout << "2: White Coffee\n";
                std::cout << "Enter your choice: ";
                std::cin >> drinkChoice;

                int sugarAmount;
                do {
                    std::cout << "Enter the number of sugars: ";
                    std::cin >> sugarAmount;
                    if (sugarAmount < 0) {
                        std::cout << "Invalid sugar amount. Please try again.\n";
                    }
                } while (sugarAmount < 0);

                switch (drinkChoice) {
                    case 1:
                        order.addDrinkItem("Black Coffee", sugarAmount);
                        std::cout << "Black Coffee with " << sugarAmount << " sugar(s) added to your order.\n";
                        break;
                    case 2:
                        order.addDrinkItem("White Coffee", sugarAmount);
                        std::cout << "White Coffee with " << sugarAmount << " sugar(s) added to your order.\n";
                        break;
                    default:
                        std::cout << "Invalid choice. Drink item not added.\n";
                        break;
                }
                break;
            }
            case 3: {
                if (order.isEmpty()) {
                    std::cout << "\nYour order is empty.\nPlease add at least one item before placing an order.\n";
                } else {
                    std::cout << "\n===== Order Summary =====\n";
                    order.displayOrder();
                    std::cout << "\nDo you want to proceed with placing the order? (Y/N): ";
                    char confirmation;
                    std::cin >> confirmation;
                    if (confirmation == 'Y' || confirmation == 'y') {
                        patron.placeOrder(std::unique_ptr<Order>(new Order(patron)));
                        host.takeOrder(patron);
                    } else {
                        std::cout << "Order cancelled.\n";
                    }
                }
                break;
            }
            case 0:
                std::cout << "\nThank you for visiting Cafe++! Have a great day!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}