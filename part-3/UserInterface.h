#pragma once
#include <iostream>
#include <limits>
#include "CoffeeTypes.h"

class UserInterface {
public:
    void displayMenu();
    int getChoice();
    int getFoodChoice();
    int getDrinkChoice();
    int getBreadChoice();
    int getFillingChoice();
    CoffeeType getCoffeeTypeChoice();
    MilkType getMilkTypeChoice();
    int getSugarAmount();
    std::string getTeaType();
};