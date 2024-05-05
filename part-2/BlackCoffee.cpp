#include "BlackCoffee.h"

BlackCoffee::BlackCoffee(int sugarAmount) : Coffee(sugarAmount) {}

std::string BlackCoffee::getName() const {
    return "Black Coffee with " + std::to_string(getSugarAmount()) + " sugar(s)";
}