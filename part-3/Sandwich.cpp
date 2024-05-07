#include "Sandwich.h"

Sandwich::Sandwich(const std::string& name, BreadType bread, FillingType filling)
    : Food(name), bread(bread), filling(filling) {}

std::string Sandwich::getName() const {
    std::string breadName;
    switch (bread) {
        case BreadType::White:
            breadName = "White Bread";
            break;
        case BreadType::WholeWheat:
            breadName = "Whole Wheat Bread";
            break;
        case BreadType::Sourdough:
            breadName = "Sourdough Bread";
            break;
    }

    std::string fillingName;
    switch (filling) {
        case FillingType::HamAndCheese:
            fillingName = "Ham and Cheese";
            break;
        case FillingType::ChickenAndAvocado:
            fillingName = "Chicken and Avocado";
            break;
        case FillingType::BLT:
            fillingName = "Bacon, Lettuce, and Tomato";
            break;
    }

    return breadName + " Sandwich with " + fillingName;
}

BreadType Sandwich::getBread() const {
    return bread;
}

FillingType Sandwich::getFilling() const {
    return filling;
}