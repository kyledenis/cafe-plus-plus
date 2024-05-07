#include "Host.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include <iostream>

Host::Host() {
    manager = new Manager(this);
    foodMaker = new FoodMaker(*manager);
    coffeeMaker = new CoffeeMaker(*manager);
    currentPatron = nullptr;
    currentOrder = nullptr;
}

void Host::startInteraction() {
    std::string patronName;
    std::cout << "Welcome to Cafe++!" << std::endl;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, patronName);
    currentPatron = new Patron(patronName);
    currentOrder = new Order(*currentPatron);

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleFoodChoice(*currentOrder);
                break;
            case 2:
                handleDrinkChoice(*currentOrder);
                break;
            case 3:
                if (currentOrder->isEmpty()) {
                    std::cout << "\nYour order is empty.\nPlease add at least one item before placing an order.\n";
                } else {
                    std::cout << "\n===== Order Summary =====\n";
                    currentOrder->displayOrder();
                    std::cout << "\nDo you want to proceed with placing the order? (Y/N): ";
                    char confirmation;
                    std::cin >> confirmation;
                    if (confirmation == 'Y' || confirmation == 'y') {
                        currentPatron->placeOrder(currentOrder);
                        takeOrder(*currentPatron);
                        currentOrder = nullptr;
                    } else {
                        std::cout << "Order cancelled.\n";
                    }
                }
                break;
            case 0:
                std::cout << "\nThank you for visiting Cafe++! Have a great day!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}

void Host::takeOrder(Patron& patron) {
    std::cout << "\nHost: Welcome, " << patron.getName() << "! Your order has been received." << std::endl;
    std::cout << "Host: Please wait while we prepare your order." << std::endl;
    manager->processOrder(currentOrder);
}

void Host::notifyOrderReady(const Patron& patron) {
    std::cout << "\nHost: " << patron.getName() << ", your order is ready! Please collect it." << std::endl;
}

Order* Host::getCurrentOrder() const {
    return currentOrder;
}

void Host::displayMenu() {
    std::cout << "\n===== Cafe++ Menu =====\n";
    std::cout << "1: Add Food Item\n";
    std::cout << "2: Add Drink Item\n";
    std::cout << "3: Place Order\n";
    std::cout << "0: Exit\n";
    std::cout << "Enter your choice: ";
}

void Host::handleFoodChoice(Order& order) {
    int foodChoice;
    std::cout << "\n===== Food Items =====\n";
    std::cout << "1: Candy Bar\n";
    std::cout << "2: Bag of Chips\n";
    std::cout << "Enter your choice: ";
    std::cin >> foodChoice;

    switch (foodChoice) {
        case 1:
            order.addFoodItem(Food("Candy Bar"));
            std::cout << "Candy Bar added to your order.\n";
            break;
        case 2:
            order.addFoodItem(Food("Bag of Chips"));
            std::cout << "Bag of Chips added to your order.\n";
            break;
        default:
            std::cout << "Invalid choice. Food item not added.\n";
            break;
    }
}

void Host::handleDrinkChoice(Order& order) {
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
            order.addDrinkItem(BlackCoffee(sugarAmount));
            std::cout << "Black Coffee with " << sugarAmount << " sugar(s) added to your order.\n";
            break;
        case 2:
            order.addDrinkItem(WhiteCoffee(sugarAmount));
            std::cout << "White Coffee with " << sugarAmount << " sugar(s) added to your order.\n";
            break;
        default:
            std::cout << "Invalid choice. Drink item not added.\n";
            break;
    }
}