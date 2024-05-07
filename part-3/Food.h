#pragma once
#include <string>

class Food {
public:
    Food(const std::string& name);
    virtual ~Food() = default;
    virtual const std::string& getName() const;
protected:
    std::string name;
};