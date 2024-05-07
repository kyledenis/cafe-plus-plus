#include "Sandwich.h"

Sandwich::Sandwich(const std::string& name, const std::string& bread, const std::string& filling)
    : Food(name), bread(bread), filling(filling) {}

const std::string& Sandwich::getBread() const {
    return bread;
}

const std::string& Sandwich::getFilling() const {
    return filling;
}