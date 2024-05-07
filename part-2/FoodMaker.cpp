#include "FoodMaker.h"
#include "Manager.h"
#include <iostream>

FoodMaker::FoodMaker(Manager& manager) : manager(manager) {}

Food* FoodMaker::makeFood(const Food& item) {
    std::cout << "\nFoodMaker: Preparing " << item.getName() << std::endl;
    Food* preparedFood = new Food(item.getName());
    return preparedFood;
}