#include "CoffeeMaker.h"
#include <iostream>

void CoffeeMaker::makeBlackCoffee(int sugarAmount) {
    BlackCoffee coffee(sugarAmount);
    std::cout << "Preparing " << coffee.getName() << std::endl;
}

void CoffeeMaker::makeWhiteCoffee(CoffeeType type, MilkType milk, int sugarAmount) {
    WhiteCoffee coffee(type, milk, sugarAmount);
    std::cout << "Preparing " << coffee.getName() << std::endl;
}
