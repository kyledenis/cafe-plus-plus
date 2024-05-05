#include "FoodMaker.h"
#include <iostream>

Food* FoodMaker::makeFood(const std::string& item) {
    std::cout << "FoodMaker: Preparing " << item << std::endl;
    return new Food(item);
}