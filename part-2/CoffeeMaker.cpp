#include "CoffeeMaker.h"
#include "Manager.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include <iostream>

CoffeeMaker::CoffeeMaker(Manager& manager) : manager(manager) {}

Coffee* CoffeeMaker::makeCoffee(const std::string& type, int sugarAmount) {
    std::cout << "\nCoffeeMaker: Preparing " << type << std::endl;
    Coffee* preparedCoffee = nullptr;
    if (type == "BlackCoffee") {
        preparedCoffee = new BlackCoffee(sugarAmount);
    } else if (type == "WhiteCoffee") {
        preparedCoffee = new WhiteCoffee(sugarAmount);
    }
    if (preparedCoffee != nullptr) {
        std::cout << "CoffeeMaker: " + type + " with " + std::to_string(sugarAmount) + " sugar(s) is prepared." << std::endl;
    }
    return preparedCoffee;
}