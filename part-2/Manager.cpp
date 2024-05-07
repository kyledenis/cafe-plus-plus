#include "Manager.h"
#include "Host.h"
#include <iostream>

Manager::Manager(Host* host) : host(host), itemsRemaining(0) {
    foodMaker = new FoodMaker(*this);
    coffeeMaker = new CoffeeMaker(*this);
}

void Manager::processOrder(Order* order) {
    if (order) {
        itemsRemaining = order->getFoodItems().size() + order->getDrinkItems().size();
        for (const auto& item : order->getFoodItems()) {
            foodMaker->makeFood(item);
        }
        for (const auto& item : order->getDrinkItems()) {
            coffeeMaker->makeCoffee(item->getName(), dynamic_cast<Coffee*>(item)->getSugarAmount());
        }
    }
}

void Manager::notifyOrderReady(const Patron& patron) {
    host->notifyOrderReady(patron);
}

void Manager::itemPrepared(const std::string& message) {
    std::cout << "Manager: Received notification - " << message << std::endl;
    --itemsRemaining;
    if (itemsRemaining == 0) {
        host->notifyOrderReady(*(host->currentPatron));
        delete host->getCurrentOrder();
    }
}