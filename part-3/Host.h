// !!: why does the include statement have to be at the bottom?

#pragma once
#include <string>
#include "Order.h"
#include "Patron.h"
#include "HostInterface.h"
#include "UserInterface.h"

class Manager;  // Forward declaration of Manager

class Host : public HostInterface {
public:
    Host();
    ~Host();
    void startInteraction();
    void notifyOrderReady(const Patron& patron) override;

private:
    Manager* manager;
    Patron* currentPatron;
    UserInterface ui;
    void handleFoodChoice(Order& order);
    void handleDrinkChoice(Order& order);
    OrderType getOrderType();
};

#include "Manager.h"