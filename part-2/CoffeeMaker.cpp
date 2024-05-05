#include "CoffeeMaker.h"
#include <iostream>

Coffee* CoffeeMaker::makeCoffee(const std::string& item, int sugarAmount) {
    std::cout << "CoffeeMaker: Preparing " << item << " with " << sugarAmount << " sugars" << std::endl;
    if (item == "Black Coffee") {
        return new BlackCoffee(sugarAmount);
    } else if (item == "White Coffee") {
        return new WhiteCoffee(sugarAmount);
    }
    return nullptr;
}