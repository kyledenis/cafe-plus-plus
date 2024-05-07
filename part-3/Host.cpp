#include "Host.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include "Sandwich.h"
#include "Tea.h"
#include "CoffeeTypes.h"
#include <iostream>

Host::Host() {
    manager = new Manager(this);
    foodMaker = new FoodMaker(*manager);
    coffeeMaker = new CoffeeMaker();  // No arguments passed
    currentPatron = nullptr;
    currentOrder = nullptr;
}

Host::~Host() {
    delete currentPatron;
    currentPatron = nullptr;
    delete manager;
    delete foodMaker;
    delete coffeeMaker;
}

void Host::startInteraction() {
    std::string patronName;
    std::cout << "Welcome to Cafe++!" << std::endl;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, patronName);
    currentPatron = new Patron(patronName);

    int choice;
    do {
        currentOrder = new Order(*currentPatron, getOrderType());

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
                        currentPatron->placeOrder(currentOrder);
                        takeOrder(*currentPatron);
                        choice = 0; // Exit the inner loop
                    }
                    break;
                case 0:
                    std::cout << "\nThank you for visiting Cafe++! Have a great day!\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 0 && choice != 3);

        delete currentOrder; // Free current order memory after completion
        currentOrder = nullptr;

        std::cout << "\nDo you want to place another order? (Y/N): ";
        char repeatOrder;
        std::cin >> repeatOrder;
        if (repeatOrder != 'Y' && repeatOrder != 'y') {
            choice = 0; // Exit the outer loop
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
    std::cout << "3: Sandwich\n";
    std::cout << "Enter your choice: ";
    std::cin >> foodChoice;

    switch (foodChoice) {
        case 1:
            order.addFoodItem(std::unique_ptr<Food>(new Food("Candy Bar")));
            std::cout << "Candy Bar added to your order.\n";
            break;
        case 2:
            order.addFoodItem(std::unique_ptr<Food>(new Food("Bag of Chips")));
            std::cout << "Bag of Chips added to your order.\n";
            break;
        case 3: {
            int breadChoice, fillingChoice;
            std::string breadType, fillingType;

            std::cout << "\n===== Bread Types =====\n";
            std::cout << "1: White Bread\n";
            std::cout << "2: Whole Wheat Bread\n";
            std::cout << "3: Sourdough Bread\n";
            std::cout << "Enter your choice: ";
            std::cin >> breadChoice;

            switch (breadChoice) {
                case 1:
                    breadType = "White Bread";
                    break;
                case 2:
                    breadType = "Whole Wheat Bread";
                    break;
                case 3:
                    breadType = "Sourdough Bread";
                    break;
                default:
                    std::cout << "Invalid bread choice. Using default bread.\n";
                    breadType = "White Bread";
                    break;
            }

            std::cout << "\n===== Filling Types =====\n";
            std::cout << "1: Ham and Cheese\n";
            std::cout << "2: Turkey and Avocado\n";
            std::cout << "3: Roast Beef and Cheddar\n";
            std::cout << "Enter your choice: ";
            std::cin >> fillingChoice;

            switch (fillingChoice) {
                case 1:
                    fillingType = "Ham and Cheese";
                    break;
                case 2:
                    fillingType = "Turkey and Avocado";
                    break;
                case 3:
                    fillingType = "Roast Beef and Cheddar";
                    break;
                default:
                    std::cout << "Invalid filling choice. Using default filling.\n";
                    fillingType = "Ham and Cheese";
                    break;
            }

            order.addFoodItem(std::unique_ptr<Sandwich>(new Sandwich("Sandwich", breadType, fillingType)));
            std::cout << "Sandwich with " << breadType << " bread and " << fillingType << " filling added to your order.\n";
            break;
        }
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
    std::cout << "3: Tea\n";
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
            order.addDrinkItem(std::unique_ptr<BlackCoffee>(new BlackCoffee(sugarAmount)));
            std::cout << "Black Coffee with " << sugarAmount << " sugar(s) added to your order.\n";
            break;
        case 2: {
            int milkChoice, coffeeTypeChoice;

            do {
                std::cout << "Select coffee type:\n";
                std::cout << "1: Latte\n";
                std::cout << "2: Cappuccino\n";
                std::cout << "3: Flat White\n";
                std::cout << "Enter your choice: ";
                std::cin >> coffeeTypeChoice;

                if (coffeeTypeChoice < 1 || coffeeTypeChoice > 3) {
                    std::cout << "Invalid coffee choice. Please try again.\n";
                }
            } while (coffeeTypeChoice < 1 || coffeeTypeChoice > 3);

            CoffeeType coffeeType;
            switch (coffeeTypeChoice) {
                case 1:
                    coffeeType = CoffeeType::Latte;
                    break;
                case 2:
                    coffeeType = CoffeeType::Cappuccino;
                    break;
                case 3:
                    coffeeType = CoffeeType::FlatWhite;
                    break;
            }

            do {
                std::cout << "Select milk type:\n";
                std::cout << "1: Full Cream\n";
                std::cout << "2: Light Milk\n";
                std::cout << "3: Soy Milk\n";
                std::cout << "4: Almond Milk\n";
                std::cout << "Enter your choice: ";
                std::cin >> milkChoice;

                if (milkChoice < 1 || milkChoice > 4) {
                    std::cout << "Invalid milk choice. Please try again.\n";
                }
            } while (milkChoice < 1 || milkChoice > 4);

            MilkType milkType;
            switch (milkChoice) {
                case 1:
                    milkType = MilkType::FullCream;
                    break;
                case 2:
                    milkType = MilkType::LightMilk;
                    break;
                case 3:
                    milkType = MilkType::SoyMilk;
                    break;
                case 4:
                    milkType = MilkType::AlmondMilk;
                    break;
            }

            order.addDrinkItem(std::unique_ptr<WhiteCoffee>(new WhiteCoffee(coffeeType, milkType, sugarAmount)));
            std::cout << "White Coffee with selected coffee type, milk, and " << sugarAmount << " sugar(s) added to your order.\n";
            break;
        }
        case 3: {
            std::string teaType;
            std::cout << "Select tea type:\n";
            std::cout << "1: English Breakfast\n";
            std::cout << "2: Earl Grey\n";
            std::cout << "3: Peppermint\n";
            std::cout << "Enter your choice: ";
            int teaChoice;
            std::cin >> teaChoice;

            switch (teaChoice) {
                case 1:
                    teaType = "English Breakfast";
                    break;
                case 2:
                    teaType = "Earl Grey";
                    break;
                case 3:
                    teaType = "Peppermint";
                    break;
                default:
                    std::cout << "Invalid tea choice. Using default tea.\n";
                    teaType = "English Breakfast";
                    break;
            }

            order.addDrinkItem(std::unique_ptr<Tea>(new Tea(teaType, sugarAmount)));
            std::cout << "Tea (" << teaType << ") with " << sugarAmount << " sugar(s) added to your order.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Drink item not added.\n";
            break;
    }
}

OrderType Host::getOrderType() {
    int orderTypeChoice;
    std::cout << "\nSelect order type:\n";
    std::cout << "1: Have Here\n";
    std::cout << "2: Takeaway\n";
    std::cout << "Enter your choice: ";
    std::cin >> orderTypeChoice;

    switch (orderTypeChoice) {
        case 1:
            return OrderType::HaveHere;
        case 2:
            return OrderType::Takeaway;
        default:
            std::cout << "Invalid order type. Defaulting to Have Here.\n";
            return OrderType::HaveHere;
    }
}
