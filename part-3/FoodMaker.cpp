#include "FoodMaker.h"
#include "Manager.h"

FoodMaker::FoodMaker(Manager& manager) : manager(manager) {}

Food* FoodMaker::makeFood(Food* item) {
    return item;
}