#include "WhiteCoffee.h"

WhiteCoffee::WhiteCoffee(int sugarAmount) : Coffee(sugarAmount) {}

std::string WhiteCoffee::getName() const {
    return "White Coffee with " + std::to_string(getSugarAmount()) + " sugar(s)";
}