#pragma once
#include <string>
#include "Order.h"
#include "Manager.h"
#include "Patron.h"
#include "FoodMaker.h"
#include "CoffeeMaker.h"

class Host {
public:
    Host();
    void startInteraction();
    void takeOrder();
    void notifyOrderReady();
    Order* getCurrentOrder() const;

private:
    Manager* manager;
    FoodMaker* foodMaker;
    CoffeeMaker* coffeeMaker;
    Patron* currentPatron;
    Order* currentOrder;
    void displayMenu();
    void handleFoodChoice(Order& order);
    void handleDrinkChoice(Order& order);
};