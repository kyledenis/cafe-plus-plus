#pragma once
#include "Drink.h"

class Coffee : public Drink {
public:
    Coffee(int sugarAmount) : sugarAmount(sugarAmount) {}
    void addSugar(int amount) { sugarAmount += amount; }
    int getSugarAmount() const { return sugarAmount; }
protected:
    int sugarAmount;
};

class BlackCoffee : public Coffee {
public:
    BlackCoffee(int sugarAmount) : Coffee(sugarAmount) {}
    std::string getName() const override { return "Black Coffee with " + std::to_string(getSugarAmount()) + " sugars"; }
};

class WhiteCoffee : public Coffee {
public:
    WhiteCoffee(int sugarAmount) : Coffee(sugarAmount) {}
    std::string getName() const override { return "White Coffee with " + std::to_string(getSugarAmount()) + " sugars"; }
};
