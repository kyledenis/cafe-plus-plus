#pragma once
#include <string>

class Order;

class Patron {
public:
    Patron(const std::string& name);
    void placeOrder(Order* order);
    const std::string& getName() const { return name; }
    const Order* getCurrentOrder() const { return currentOrder; }
private:
    std::string name;
    Order* currentOrder;
};