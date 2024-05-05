#pragma once
#include "Drink.h"

class Coffee : public Drink {
public:
    Coffee(int sugarAmount);
    void addSugar(int amount);
    int getSugarAmount() const;
protected:
    int sugarAmount;
};