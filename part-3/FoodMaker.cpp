#include "FoodMaker.h"
#include "Manager.h"
#include <iostream>

FoodMaker::FoodMaker(Manager& manager) : manager(manager) {}

Food* FoodMaker::makeFood(Food* item) {
    std::cout << "FoodMaker: Preparing " << item->getName() << std::endl;
    return item;
}
