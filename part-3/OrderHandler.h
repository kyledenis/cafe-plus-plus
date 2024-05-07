#pragma once
#include <memory>
#include "Food.h"
#include "Drink.h"
#include "Sandwich.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include "Tea.h"
#include "UserInterface.h"

class OrderHandler {
public:
    static std::unique_ptr<Food> createFood(int choice);
    static std::unique_ptr<Drink> createDrink(int choice);
};