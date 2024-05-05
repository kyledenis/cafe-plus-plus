#include "Manager.h"
#include "Host.h"

void Manager::processOrder(const Order* order) {
    if (order) {
        for (const auto& item : order->getFoodItems()) {
            foodMaker.makeFood(item);
        }
        for (const auto& item : order->getDrinkItems()) {
            coffeeMaker.makeCoffee(item->getName(), dynamic_cast<Coffee*>(item)->getSugarAmount());
        }
        notifyOrderReady(order->getPatron());
    }
}

void Manager::notifyOrderReady(const Patron& patron) {
    host->notifyOrderReady(patron);
}