#pragma once
#include "Coffee.h"

class CoffeeMaker {
public:
    Coffee* makeCoffee(const std::string& item, int sugarAmount);
};