#pragma once
#include <vector>
#include "Patron.h"
#include "Food.h"
#include "Drink.h"

class Order {
public:
    Order(const Patron& patron);
    void addFoodItem(const Food& item);
    void addDrinkItem(const Drink& item);
    const std::vector<Food>& getFoodItems() const;
    const std::vector<Drink*>& getDrinkItems() const;
    const Patron& getPatron() const;
    bool isEmpty() const;
    void displayOrder() const;
private:
    const Patron& patron;
    std::vector<Food> foodItems;
    std::vector<Drink*> drinkItems;
};