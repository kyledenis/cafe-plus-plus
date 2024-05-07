#include "Manager.h"
#include "Host.h"
#include <iostream>

Manager::Manager(Host* host) : host(host) {
    foodMaker = new FoodMaker(*this);
    coffeeMaker = new CoffeeMaker();
}

Manager::~Manager() {
    delete foodMaker;
    delete coffeeMaker;
}

void Manager::notifyOrderReady(const Patron& patron) {
    std::cout << "\nManager: Order for " << patron.getName() << " is ready!" << std::endl;
}

void Manager::processOrder(Order* order) {
    std::cout << "\nProcessing order for " << order->getPatron().getName() << ":\n";

    std::cout << "\nFood Items:\n";
    for (const auto& item : order->getFoodItems()) {
        Food* food = foodMaker->makeFood(item.get());
        std::cout << "- " << food->getName() << "\n";
    }

    std::cout << "\nDrink Items:\n";
    for (const auto& item : order->getDrinkItems()) {
        Drink* drink = coffeeMaker->makeDrink(item.get());
        std::cout << "- " << drink->getName() << "\n";
    }

    std::cout << "Order complete.\n";
    notifyOrderReady(order->getPatron());
}