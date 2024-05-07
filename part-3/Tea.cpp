#include "Tea.h"

Tea::Tea(const std::string& type, int sugar) : type(type) {
    sugarAmount = sugar;
}

std::string Tea::getName() const {
    return type + " Tea with " + std::to_string(sugarAmount) + " sugar(s)";
}