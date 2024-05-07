#pragma once
#include "MenuItem.h"

class Drink : public MenuItem {
public:
    virtual ~Drink() = default;
    virtual std::string getName() const override = 0;
    virtual int getSugarAmount() const;
    virtual void addSugar(int amount);

protected:
    int sugarAmount = 0;
};