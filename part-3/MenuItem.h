#pragma once
#include <string>

class MenuItem {
public:
    virtual ~MenuItem() = default;
    virtual std::string getName() const = 0;
};