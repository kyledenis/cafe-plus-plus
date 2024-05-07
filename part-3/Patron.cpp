#include "Patron.h"
#include "Order.h"

Patron::Patron(const std::string& name) : name(name) {}

const std::string& Patron::getName() const {
    return name;
}

void Patron::placeOrder(Order* order) {
    orders.push_back(order);
}

const std::vector<Order*>& Patron::getOrders() const {
    return orders;
}