#pragma once
#include <string>

enum class CoffeeType {
    Latte,
    Cappuccino,
    FlatWhite
};

enum class MilkType {
    FullCream,
    LightMilk,
    AlmondMilk
};

std::string CoffeeTypeToString(CoffeeType type);
std::string MilkTypeToString(MilkType type);