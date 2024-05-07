#include "Order.h"
#include <iostream>

Order::Order(const Patron& patron, OrderType orderType) : patron(patron), orderType(orderType) {}

void Order::addFoodItem(std::unique_ptr<Food> item) {
    foodItems.push_back(std::move(item));
}

void Order::addDrinkItem(std::unique_ptr<Drink> item) {
    drinkItems.push_back(std::move(item));
}

const std::vector<std::unique_ptr<Food>>& Order::getFoodItems() const {
    return foodItems;
}

const std::vector<std::unique_ptr<Drink>>& Order::getDrinkItems() const {
    return drinkItems;
}

const Patron& Order::getPatron() const {
    return patron;
}

OrderType Order::getOrderType() const {
    return orderType;
}

bool Order::isEmpty() const {
    return foodItems.empty() && drinkItems.empty();
}