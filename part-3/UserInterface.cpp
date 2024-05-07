#include "UserInterface.h"

void UserInterface::displayMenu() {
    std::cout << "\n===== Cafe++ Menu =====\n";
    std::cout << "1: Add Food Item\n";
    std::cout << "2: Add Drink Item\n";
    std::cout << "3: Place Order\n";
    std::cout << "0: Exit\n";
    std::cout << "Enter your choice: ";
}

int UserInterface::getChoice() {
    int choice;
    std::cin >> choice;
    while (std::cin.fail() || choice < 0 || choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Please try again: ";
        std::cin >> choice;
    }
    return choice;
}

int UserInterface::getFoodChoice() {
    std::cout << "\n===== Food Items =====\n";
    std::cout << "1: Candy Bar\n";
    std::cout << "2: Bag of Chips\n";
    std::cout << "3: Sandwich\n";
    std::cout << "Enter your choice: ";
    return getChoice();
}

int UserInterface::getDrinkChoice() {
    std::cout << "\n===== Drink Items =====\n";
    std::cout << "1: Black Coffee\n";
    std::cout << "2: White Coffee\n";
    std::cout << "3: Tea\n";
    std::cout << "Enter your choice: ";
    return getChoice();
}

int UserInterface::getBreadChoice() {
    std::cout << "\n===== Bread Types =====\n";
    std::cout << "1: White Bread\n";
    std::cout << "2: Whole Wheat Bread\n";
    std::cout << "3: Sourdough Bread\n";
    std::cout << "Enter your choice: ";
    int breadChoice;
    std::cin >> breadChoice;

    while (std::cin.fail() || breadChoice < 1 || breadChoice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid bread choice. Please try again: ";
        std::cin >> breadChoice;
    }
    return breadChoice;
}

int UserInterface::getFillingChoice() {
    std::cout << "\n===== Filling Types =====\n";
    std::cout << "1: Ham and Cheese\n";
    std::cout << "2: Chicken and Avocado\n";
    std::cout << "3: BLT\n";
    std::cout << "Enter your choice: ";
    int fillingChoice;
    std::cin >> fillingChoice;
    
    while (std::cin.fail() || fillingChoice < 1 || fillingChoice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid filling choice. Please try again: ";
        std::cin >> fillingChoice;
    }
    return fillingChoice;
}

CoffeeType UserInterface::getCoffeeTypeChoice() {
    std::cout << "\nSelect coffee type:\n";
    std::cout << "1: Latte\n";
    std::cout << "2: Cappuccino\n";
    std::cout << "3: Flat White\n";
    std::cout << "Enter your choice: ";
    int choice = getChoice();

    switch (choice) {
        case 1: return CoffeeType::Latte;
        case 2: return CoffeeType::Cappuccino;
        case 3: return CoffeeType::FlatWhite;
        default: return CoffeeType::Latte;
    }
}

MilkType UserInterface::getMilkTypeChoice() {
    std::cout << "\nSelect milk type:\n";
    std::cout << "1: Full Cream\n";
    std::cout << "2: Light Milk\n";
    std::cout << "3: Almond Milk\n";
    std::cout << "Enter your choice: ";
    int choice = getChoice();

    switch (choice) {
        case 1: return MilkType::FullCream;
        case 2: return MilkType::LightMilk;
        case 3: return MilkType::AlmondMilk;
        default: return MilkType::FullCream;
    }
}

int UserInterface::getSugarAmount() {
    std::cout << "Enter the number of sugars: ";
    int sugarAmount;
    std::cin >> sugarAmount;
    while (std::cin.fail() || sugarAmount < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid sugar amount. Please try again: ";
        std::cin >> sugarAmount;
    }
    return sugarAmount;
}

std::string UserInterface::getTeaType() {
    int teaTypeChoice;
    std::cout << "\nSelect tea type:\n";
    std::cout << "1: English Breakfast\n";
    std::cout << "2: Earl Grey\n";
    std::cout << "3: Peppermint\n";
    std::cout << "Enter your choice: ";
    teaTypeChoice = getChoice();

    switch (teaTypeChoice) {
        case 1:
            return "English Breakfast";
        case 2:
            return "Earl Grey";
        case 3:
            return "Peppermint";
        default:
            std::cout << "Invalid tea choice. Using default tea.\n";
            return "English Breakfast";
    }
}