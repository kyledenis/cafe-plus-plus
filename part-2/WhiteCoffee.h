#pragma once
#include "Coffee.h"

class WhiteCoffee : public Coffee {
public:
    WhiteCoffee(int sugarAmount);
    std::string getName() const override;
};