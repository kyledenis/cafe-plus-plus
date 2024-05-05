#pragma once
#include <string>

class Drink {
public:
    virtual ~Drink() = default;
    virtual std::string getName() const = 0;
};