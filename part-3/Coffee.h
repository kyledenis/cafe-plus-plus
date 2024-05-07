#pragma once
#include "Drink.h"

class Coffee : public Drink {
public:
    explicit Coffee(int sugar = 0);
    std::string getName() const override;
protected:
    int sugarAmount;
};