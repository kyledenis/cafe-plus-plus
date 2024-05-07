#include "Manager.h"
#include "Host.h"
#include <iostream>

Manager::Manager(Host* host) : host(host), itemsRemaining(0) {
    foodMaker = new FoodMaker(*this);
    coffeeMaker = new CoffeeMaker(*this);
}

void Manager::processOrder(Order* order) {
    std::cout << "\nProcessing order for " << order->getPatron().getName() << "..." << std::endl;

    for (const auto& item : order->getFoodItems()) {
        foodMaker->makeFood(item);
        std::cout << "FoodMaker: " + item.getName() + " is prepared." << std::endl;
    }

    for (const auto& item : order->getDrinkItems()) {
        coffeeMaker->makeCoffee(item->getName(), dynamic_cast<const Coffee*>(item.get())->getSugarAmount());
        std::cout << "CoffeeMaker: " + item->getName() + " is prepared." << std::endl;
    }

    std::cout << "\nOrder complete." << std::endl;
    notifyOrderReady(order->getPatron());
}

void Manager::notifyOrderReady(const Patron& patron) {
    host->notifyOrderReady();
}
