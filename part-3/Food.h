#pragma once
#include "MenuItem.h"

class Food : public MenuItem {
public:
    Food(const std::string& name);
    virtual ~Food() = default;
    std::string getName() const override;
protected:
    std::string name;
};