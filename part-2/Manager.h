#pragma once
#include "Order.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"
#include "Patron.h"

class Host;

class Manager {
public:
    Manager(Host* host);
    void processOrder(Order* order);
    void notifyOrderReady(const Patron& patron);
private:
    FoodMaker* foodMaker;
    CoffeeMaker* coffeeMaker;
    Host* host;
    int itemsRemaining;
};