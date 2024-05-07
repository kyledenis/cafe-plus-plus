#pragma once
#include "Patron.h"

class HostInterface {
public:
    virtual ~HostInterface() = default;
    virtual void notifyOrderReady(const Patron& patron) = 0;
};