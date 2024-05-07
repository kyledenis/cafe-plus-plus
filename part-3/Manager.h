#pragma once
#include "Order.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"

class Host;

class Manager {
public:
    Manager(Host* host);
    ~Manager();
    void processOrder(Order* order);

private:
    std::unique_ptr<FoodMaker> foodMaker;
    std::unique_ptr<CoffeeMaker> coffeeMaker;
    Host* host;
};
