#pragma once
#include "Order.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"
#include "Patron.h"

class Host;

class Manager {
public:
    void processOrder(const Order* order);
    void notifyOrderReady(const Patron& patron);
private:
    FoodMaker foodMaker;
    CoffeeMaker coffeeMaker;
    Host* host;
};