// Coffee.cpp
#include "Coffee.h"
#include <string>

Coffee::Coffee(int sugar) : sugarAmount(sugar) {}

std::string Coffee::getName() const {
    return "Coffee with " + std::to_string(sugarAmount) + " sugar(s)";
}
