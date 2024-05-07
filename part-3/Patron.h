#pragma once
#include <string>
#include <vector>

class Order;

class Patron {
public:
    Patron(const std::string& name);
    const std::string& getName() const;
    void placeOrder(Order* order);
    const std::vector<Order*>& getOrders() const;

private:
    std::string name;
    std::vector<Order*> orders;
};