#include "Patron.h"

Patron::Patron(const std::string& name) : name(name), currentOrder(nullptr) {}

void Patron::placeOrder(Order* order) {
    currentOrder = order;
}