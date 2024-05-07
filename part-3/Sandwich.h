#pragma once
#include "Food.h"

class Sandwich : public Food {
public:
    Sandwich(const std::string& name, const std::string& bread, const std::string& filling);
    const std::string& getBread() const;
    const std::string& getFilling() const;
private:
    std::string bread;
    std::string filling;
};