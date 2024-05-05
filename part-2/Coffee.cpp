#include "Coffee.h"

Coffee::Coffee(int sugarAmount) : sugarAmount(sugarAmount) {}

void Coffee::addSugar(int amount) {
    sugarAmount += amount;
}

int Coffee::getSugarAmount() const {
    return sugarAmount;
}