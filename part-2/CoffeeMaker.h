#pragma once
#include "Coffee.h"

class Manager;

class CoffeeMaker {
public:
    CoffeeMaker(Manager& manager);
    Coffee* makeCoffee(const std::string& type, int sugarAmount);
private:
    Manager& manager;
};