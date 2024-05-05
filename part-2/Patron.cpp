#include "Patron.h"
#include "Order.h"

void Patron::placeOrder(std::unique_ptr<Order> order) {
    currentOrder = std::move(order);
}