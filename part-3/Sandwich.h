#pragma once
#include "Food.h"

enum class BreadType {
    White,
    WholeWheat,
    Sourdough
};

enum class FillingType {
    HamAndCheese,
    ChickenAndAvocado,
    BLT
};

class Sandwich : public Food {
public:
    Sandwich(const std::string& name, BreadType bread, FillingType filling);
    std::string getName() const override;
    BreadType getBread() const;
    FillingType getFilling() const;
private:
    BreadType bread;
    FillingType filling;
};