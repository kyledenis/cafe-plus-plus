#include "Host.h"
#include <iostream>

void Host::takeOrder(Patron& patron) {
    std::cout << "\nHost: Welcome, " << patron.getName() << "! Your order has been received." << std::endl;
    std::cout << "Host: Please wait while we prepare your order." << std::endl;
    manager.processOrder(patron.getCurrentOrder());
}

void Host::notifyOrderReady(const Patron& patron) {
    std::cout << "\nHost: " << patron.getName() << ", your order is ready! Please collect it." << std::endl;
}