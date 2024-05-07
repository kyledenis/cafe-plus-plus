#pragma once
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include "CoffeeTypes.h"

class CoffeeMaker {
public:
    CoffeeMaker() = default;  // Default constructor
    void makeBlackCoffee(int sugarAmount);
    void makeWhiteCoffee(CoffeeType type, MilkType milk, int sugarAmount);
};
