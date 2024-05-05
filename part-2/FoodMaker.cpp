#include "FoodMaker.h"
#include <iostream>

Food* FoodMaker::makeFood(const Food& item) {
    std::cout << "FoodMaker: Preparing " << item.getName() << std::endl;
    return new Food(item.getName());
}