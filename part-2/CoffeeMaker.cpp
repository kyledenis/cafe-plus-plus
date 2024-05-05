#include "CoffeeMaker.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include <iostream>

Coffee* CoffeeMaker::makeCoffee(const std::string& type, int sugarAmount) {
    std::cout << "CoffeeMaker: Preparing " << type << " with " << sugarAmount << " sugar(s)" << std::endl;
    if (type == "BlackCoffee") {
        return new BlackCoffee(sugarAmount);
    } else if (type == "WhiteCoffee") {
        return new WhiteCoffee(sugarAmount);
    }
    return nullptr;
}