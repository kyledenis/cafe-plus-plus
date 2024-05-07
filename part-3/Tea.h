#pragma once
#include "Drink.h"
#include <string>

// Derived class specific to tea drinks
class Tea : public Drink {
public:
    Tea(const std::string& type, int sugar = 0);

    // Override to give tea-specific name
    std::string getName() const override;

private:
    std::string type;
};
