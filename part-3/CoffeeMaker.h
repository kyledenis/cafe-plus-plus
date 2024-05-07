#pragma once
#include "Drink.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include "Tea.h"

class CoffeeMaker {
public:
    CoffeeMaker() = default;
    Drink* makeDrink(Drink* drink);
};