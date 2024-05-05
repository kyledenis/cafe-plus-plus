#pragma once
#include <string>

class Food {
public:
    Food(const std::string& name) : name(name) {}
    const std::string& getName() const { return name; }
private:
    std::string name;
};