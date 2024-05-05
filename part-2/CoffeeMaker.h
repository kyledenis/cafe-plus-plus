#pragma once
#include "Coffee.h"

class CoffeeMaker {
public:
    Coffee* makeCoffee(const std::string& type, int sugarAmount);
};