#pragma once
#include "Coffee.h"

class BlackCoffee : public Coffee {
public:
    BlackCoffee(int sugarAmount);
    std::string getName() const override;
};