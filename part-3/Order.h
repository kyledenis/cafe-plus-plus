#pragma once
#include <vector>
#include <memory>
#include "Patron.h"
#include "MenuItem.h"
#include "Food.h"
#include "Drink.h"

enum class OrderType {
    HaveHere,
    Takeaway
};

class Order {
public:
    Order(const Patron& patron, OrderType orderType);
    void addFoodItem(std::unique_ptr<Food> item);
    void addDrinkItem(std::unique_ptr<Drink> item);
    const std::vector<std::unique_ptr<Food>>& getFoodItems() const;
    const std::vector<std::unique_ptr<Drink>>& getDrinkItems() const;
    const Patron& getPatron() const;
    OrderType getOrderType() const;
    bool isEmpty() const;
private:
    const Patron& patron;
    std::vector<std::unique_ptr<Food>> foodItems;
    std::vector<std::unique_ptr<Drink>> drinkItems;
    OrderType orderType;
};