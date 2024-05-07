#pragma once
#include "Food.h"

class Manager;

class FoodMaker {
public:
    FoodMaker(Manager& manager);
    Food* makeFood(const Food& item);
private:
    Manager& manager;
};