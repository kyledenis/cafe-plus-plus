// Coffee.h
#pragma once
#include "Drink.h"

class Coffee : public Drink {
public:
    explicit Coffee(int sugar = 0);
    virtual std::string getName() const override;
protected:
    int sugarAmount;
};
