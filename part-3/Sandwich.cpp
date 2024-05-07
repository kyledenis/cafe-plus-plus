#include "Sandwich.h"

Sandwich::Sandwich(const std::string& name, BreadType bread, FillingType filling)
    : Food(name), bread(bread), filling(filling) {}

BreadType Sandwich::getBread() const {
    return bread;
}

FillingType Sandwich::getFilling() const {
    return filling;
}