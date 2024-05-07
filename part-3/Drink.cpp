#include "Drink.h"

// Provide default implementations for sugar handling
int Drink::getSugarAmount() const {
    return sugarAmount;
}

void Drink::addSugar(int amount) {
    sugarAmount += amount;
}
