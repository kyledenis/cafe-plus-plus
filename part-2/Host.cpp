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
                    std::cout << "\nYour order is empty.\nPlease add at least one item before placing an order." << std::endl;
                } else {
                    std::cout << "\n===== Order Summary =====" << std::endl;
                    currentOrder->displayOrder();
                    std::cout << "\nDo you want to proceed with placing the order? (Y/N): ";
                    char confirmation;
                    std::cin >> confirmation;
                    if (confirmation == 'Y' || confirmation == 'y') {
                        currentPatron->placeOrder(currentOrder);
                        takeOrder();
                    } else {
                        std::cout << "Order cancelled." << std::endl;
                    }
                }
                break;
            case 0:
                std::cout << "\nThank you for visiting Cafe++!\nHave a great day!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);

    delete currentPatron;
    delete currentOrder;
}

void Host::takeOrder() {
    std::cout << "\n===== Order Status =====" << std::endl;
    std::cout << "Host: Welcome, " << currentPatron->getName() << "! Your order has been received." << std::endl;
    std::cout << "Host: Please wait while we prepare your order." << std::endl;
    manager->processOrder(currentOrder);
}

void Host::notifyOrderReady() {
    std::cout << "Host: " << currentPatron->getName() << ", your order is ready! Please collect it." << std::endl;
}

Order* Host::getCurrentOrder() const {
    return currentOrder;
}

void Host::displayMenu() {
    std::cout << "\n===== Cafe++ Menu =====" << std::endl;
    std::cout << "1: Add Food Item" << std::endl;
    std::cout << "2: Add Drink Item" << std::endl;
    std::cout << "3: Place Order" << std::endl;
    std::cout << "0: Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void Host::handleFoodChoice(Order& order) {
    int foodChoice;
    std::cout << "\n===== Food Items =====" << std::endl;
    std::cout << "1: Candy Bar" << std::endl;
    std::cout << "2: Bag of Chips" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> foodChoice;

    switch (foodChoice) {
        case 1:
            order.addFoodItem(Food("Candy Bar"));
            std::cout << "Candy Bar added to your order." << std::endl;
            break;
        case 2:
            order.addFoodItem(Food("Bag of Chips"));
            std::cout << "Bag of Chips added to your order." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Food item not added." << std::endl;
            break;
    }
}

void Host::handleDrinkChoice(Order& order) {
    int drinkChoice;
    std::cout << "\n===== Drink Items =====" << std::endl;
    std::cout << "1: Black Coffee" << std::endl;
    std::cout << "2: White Coffee" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> drinkChoice;

    int sugarAmount;
    do {
        std::cout << "Enter the number of sugars: ";
        std::cin >> sugarAmount;
        if (sugarAmount < 0) {
            std::cout << "Invalid sugar amount. Please try again." << std::endl;
        }
    } while (sugarAmount < 0);

    switch (drinkChoice) {
        case 1:
            order.addDrinkItem(std::make_unique<BlackCoffee>(sugarAmount));
            std::cout << "Black Coffee with " << sugarAmount << " sugar(s) added to your order." << std::endl;
            break;
        case 2:
            order.addDrinkItem(std::make_unique<WhiteCoffee>(sugarAmount));
            std::cout << "White Coffee with " << sugarAmount << " sugar(s) added to your order." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Drink item not added." << std::endl;
            break;
    }
}