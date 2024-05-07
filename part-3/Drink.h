#pragma once
#include <string>

// Base class for all drinks
class Drink {
public:
    virtual ~Drink() = default;
    virtual std::string getName() const = 0;

    // Common sugar handling for all derived drinks
    virtual int getSugarAmount() const;
    virtual void addSugar(int amount);

protected:
    int sugarAmount = 0;
};
