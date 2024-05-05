#pragma once
#include <string>
#include <vector>
#include "Patron.h"
#include "Food.h"
#include "Drink.h"

class Order {
public:
    Order(const Patron& patron) : patron(patron) {}
    void addFoodItem(const std::string& item);
    void addDrinkItem(const std::string& item, int sugarAmount);
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