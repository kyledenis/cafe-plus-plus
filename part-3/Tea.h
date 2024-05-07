#pragma once
#include "Drink.h"
#include <string>

class Tea : public Drink {
public:
    Tea(const std::string& type, int sugar = 0);
    std::string getName() const override;

private:
    std::string type;
};