#pragma once
#include <string>
#include <memory>

class Order;

class Patron {
public:
    Patron(const std::string& name) : name(name), currentOrder(nullptr) {}
    void placeOrder(std::unique_ptr<Order> order);
    const std::string& getName() const { return name; }
    const Order* getCurrentOrder() const { return currentOrder.get(); }
private:
    std::string name;
    std::unique_ptr<Order> currentOrder;
};