// TODO: WhiteCoffee class should probably handle the enums

#pragma once
#include "Coffee.h"
#include "CoffeeTypes.h"

class WhiteCoffee : public Coffee {
public:
    WhiteCoffee(CoffeeType coffeeType, MilkType milkType, int sugar = 0);
    std::string getName() const override;
    static std::string CoffeeTypeToString(CoffeeType type);
    static std::string MilkTypeToString(MilkType type);
    CoffeeType getCoffeeType() const;
    MilkType getMilkType() const;

private:
    CoffeeType coffeeType;
    MilkType milkType;
};
