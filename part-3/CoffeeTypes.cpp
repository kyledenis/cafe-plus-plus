#include "CoffeeTypes.h"

std::string CoffeeTypeToString(CoffeeType type) {
    switch (type) {
        case CoffeeType::Latte: return "Latte";
        case CoffeeType::Cappuccino: return "Cappuccino";
        case CoffeeType::FlatWhite: return "Flat White";
        default: return "Unknown Type";
    }
}

std::string MilkTypeToString(MilkType type) {
    switch (type) {
        case MilkType::FullCream: return "Full Cream";
        case MilkType::LightMilk: return "Light Milk";
        case MilkType::AlmondMilk: return "Almond Milk";
        default: return "Unknown Milk Type";
    }
}