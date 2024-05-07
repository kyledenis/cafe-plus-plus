#include "Food.h"

Food::Food(const std::string& name) : name(name) {}

const std::string& Food::getName() const {
    return name;
}