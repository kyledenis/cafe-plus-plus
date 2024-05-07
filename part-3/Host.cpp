#include "Host.h"
#include "OrderHandler.h"
#include <iostream>

Host::Host() {
    manager = new Manager(this);
    currentPatron = nullptr;
}

Host::~Host() {
    delete manager;
    delete currentPatron;
}

void Host::startInteraction() {
    std::string patronName;
    std::cout << "Welcome to Cafe++!" << std::endl;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, patronName);
    currentPatron = new Patron(patronName);

    int choice;
    do {
        Order* currentOrder = new Order(*currentPatron, getOrderType());

        do {
            ui.displayMenu();
            choice = ui.getChoice();

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
                        manager->processOrder(currentOrder);
                        choice = 0; // Exit the inner loop
                    }
                    break;
                case 0:
                    std::cout << "\nThank you for visiting Cafe++! Have a great day!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        } while (choice != 0 && choice != 3);

        delete currentOrder; // Free current order memory after completion
    } while (choice != 0);

    delete currentPatron;
    currentPatron = nullptr;
}

void Host::handleFoodChoice(Order& order) {
    int choice = ui.getFoodChoice();
    std::unique_ptr<Food> food = OrderHandler::createFood(choice);
    if (food) {
        std::string foodName = food->getName();  // Store the food name
        order.addFoodItem(std::move(food));
        std::cout << foodName << " added to your order." << std::endl;  // Use the stored food name
    } else {
        std::cout << "Invalid choice. Food item not added." << std::endl;
    }
}

void Host::handleDrinkChoice(Order& order) {
    int choice = ui.getDrinkChoice();
    std::unique_ptr<Drink> drink = OrderHandler::createDrink(choice);
    if (drink) {
        std::string drinkName = drink->getName();  // Store the drink name
        order.addDrinkItem(std::move(drink));
        std::cout << drinkName << " added to your order." << std::endl;  // Use the stored drink name
    } else {
        std::cout << "Invalid choice. Drink item not added." << std::endl;
    }
}

OrderType Host::getOrderType() {
    int orderTypeChoice;
    std::cout << "\nSelect order type:" << std::endl;
    std::cout << "1: Have Here" << std::endl;
    std::cout << "2: Takeaway" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> orderTypeChoice;

    switch (orderTypeChoice) {
        case 1:
            return OrderType::HaveHere;
        case 2:
            return OrderType::Takeaway;
        default:
            std::cout << "Invalid order type. Defaulting to Have Here." << std::endl;
            return OrderType::HaveHere;
    }
}

void Host::notifyOrderReady(const Patron& patron) {
    std::cout << "\nHost: Order for " << patron.getName() << " is ready!" << std::endl;
}