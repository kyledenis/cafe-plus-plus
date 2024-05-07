#include "Manager.h"
#include "Host.h"
#include "Tea.h"
#include <iostream>

Manager::Manager(Host* host) : host(host) {
    foodMaker = std::make_unique<FoodMaker>(*this);
    coffeeMaker = std::make_unique<CoffeeMaker>();  // Initialized correctly
}

Manager::~Manager() = default;

void Manager::processOrder(Order* order) {
    if (order) {
        for (const auto& item : order->getFoodItems()) {
            foodMaker->makeFood(item.get());
        }
        for (const auto& item : order->getDrinkItems()) {
            if (auto whiteCoffee = dynamic_cast<WhiteCoffee*>(item.get())) {
                coffeeMaker->makeWhiteCoffee(whiteCoffee->getCoffeeType(), whiteCoffee->getMilkType(), whiteCoffee->getSugarAmount());
            } else if (auto blackCoffee = dynamic_cast<BlackCoffee*>(item.get())) {
                coffeeMaker->makeBlackCoffee(blackCoffee->getSugarAmount());
            } else if (auto tea = dynamic_cast<Tea*>(item.get())) {
                std::cout << "Preparing " << tea->getName() << std::endl;
            } else {
                std::cerr << "Unknown drink type." << std::endl;
            }
        }
    }
}