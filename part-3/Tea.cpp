#include "Tea.h"

// Constructor initializes tea-specific attributes and base class sugar amount
Tea::Tea(const std::string& type, int sugar) : type(type) {
    sugarAmount = sugar;
}

// Override `getName` to describe the tea type and sugar content
std::string Tea::getName() const {
    return type + " Tea with " + std::to_string(sugarAmount) + " sugar(s)";
}
