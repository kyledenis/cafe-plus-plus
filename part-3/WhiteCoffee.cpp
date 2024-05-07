#include "WhiteCoffee.h"

WhiteCoffee::WhiteCoffee(CoffeeType coffeeType, MilkType milkType, int sugar)
    : Coffee(sugar), coffeeType(coffeeType), milkType(milkType) {}

std::string WhiteCoffee::getName() const {
    return CoffeeTypeToString(coffeeType) + " with " + MilkTypeToString(milkType) + " and " + std::to_string(getSugarAmount()) + " sugar(s)";
}

CoffeeType WhiteCoffee::getCoffeeType() const {
    return coffeeType;
}

MilkType WhiteCoffee::getMilkType() const {
    return milkType;
}