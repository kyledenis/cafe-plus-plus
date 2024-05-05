#include "Order.h"
#include <iostream>

void Order::addFoodItem(const Food& item) {
    foodItems.push_back(item);
}

void Order::addDrinkItem(const Drink& item) {
    drinkItems.push_back(const_cast<Drink*>(&item));
}

const std::vector<std::string>& Order::getFoodItems() const {
    return foodItems;
}

const std::vector<std::pair<std::string, int>>& Order::getDrinkItems() const {
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
        std::cout << "- " << item << std::endl;
    }
    std::cout << "Drink Items:" << std::endl;
    for (const auto& item : drinkItems) {
        std::cout << "- " << item.first << " with " << item.second << " sugars" << std::endl;
    }
}