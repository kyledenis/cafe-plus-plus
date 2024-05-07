#pragma once
#include "Order.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"

class Host;  // Forward declaration of Host
class HostInterface;  // Forward declaration of HostInterface

class Manager {
public:
    Manager(Host* host);
    ~Manager();
    void processOrder(Order* order);
    void notifyOrderReady(const Patron& patron);

private:
    Host* host;
    FoodMaker* foodMaker;
    CoffeeMaker* coffeeMaker;
};