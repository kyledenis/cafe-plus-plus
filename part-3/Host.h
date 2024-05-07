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
    ~Host();
    void startInteraction();
    void takeOrder(Patron& patron);
    void notifyOrderReady(const Patron& patron);
    Order* getCurrentOrder() const;

    Patron* currentPatron;
private:
    Manager* manager;
    FoodMaker* foodMaker;
    CoffeeMaker* coffeeMaker;
    Order* currentOrder;
    void displayMenu();
    void handleFoodChoice(Order& order);
    void handleDrinkChoice(Order& order);
    OrderType getOrderType();
};