#pragma once
#include <string>
#include "Order.h"
#include "Manager.h"
#include "Patron.h"

class Host {
public:
    void takeOrder(Patron& patron);
    void notifyOrderReady(const Patron& patron);
private:
    Manager manager;
};