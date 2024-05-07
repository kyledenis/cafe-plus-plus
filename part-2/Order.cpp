#include "Order.h"
#include <iostream>

Order::Order(const Patron& patron) : patron(patron) {}

void Order::addFoodItem(const Food& item) {
    foodItems.push_back(item);
}

void Order::addDrinkItem(std::unique_ptr<Drink> item) {
    drinkItems.push_back(std::move(item));
}

const std::vector<Food>& Order::getFoodItems() const {
    return foodItems;
}

const std::vector<std::unique_ptr<Drink>>& Order::getDrinkItems() const {
    return drinkItems;
}

const Patron& Order::getPatron() const {
    return patron;
}

bool Order::isEmpty() const {
    return foodItems.empty() && drinkItems.empty();
}

void Order::displayOrder() const {
    std::cout << "Order Summary:" << std::endl;
    std::cout << "Food Items:" << std::endl;
    for (const auto& item : foodItems) {
        std::cout << "- " << item.getName() << std::endl;
    }
    std::cout << "Drink Items:" << std::endl;
    for (const auto& item : drinkItems) {
        std::cout << "- " << item->getName() << std::endl;
    }
}