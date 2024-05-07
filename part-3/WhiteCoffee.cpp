#include "WhiteCoffee.h"
#include <string>

WhiteCoffee::WhiteCoffee(CoffeeType coffeeType, MilkType milkType, int sugar)
    : Coffee(sugar), coffeeType(coffeeType), milkType(milkType) {}

std::string WhiteCoffee::getName() const {
    return WhiteCoffee::CoffeeTypeToString(coffeeType) + " with " + WhiteCoffee::MilkTypeToString(milkType) + " and " + std::to_string(sugarAmount) + " sugar(s)";
}

std::string WhiteCoffee::CoffeeTypeToString(CoffeeType type) {
    switch (type) {
        case CoffeeType::Latte: return "Latte";
        case CoffeeType::Cappuccino: return "Cappuccino";
        case CoffeeType::FlatWhite: return "Flat White";
        default: return "Unknown Type";
    }
}

std::string WhiteCoffee::MilkTypeToString(MilkType type) {
    switch (type) {
        case MilkType::FullCream: return "Full Cream";
        case MilkType::LightMilk: return "Light Milk";
        case MilkType::SoyMilk: return "Soy Milk";
        case MilkType::AlmondMilk: return "Almond Milk";
        default: return "Unknown Milk Type";
    }
}

CoffeeType WhiteCoffee::getCoffeeType() const {
    return coffeeType;
}

MilkType WhiteCoffee::getMilkType() const {
    return milkType;
}