#include "Drink.h"

int Drink::getSugarAmount() const {
    return sugarAmount;
}

void Drink::addSugar(int amount) {
    sugarAmount += amount;
}