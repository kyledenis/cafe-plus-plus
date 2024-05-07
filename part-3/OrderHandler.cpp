#include "OrderHandler.h"

std::unique_ptr<Food> OrderHandler::createFood(int choice) {
    UserInterface ui;
    switch (choice) {
        case 1:
            return std::make_unique<Food>("Candy Bar");
        case 2:
            return std::make_unique<Food>("Bag of Chips");
        case 3: {
            int breadChoice = ui.getBreadChoice();
            int fillingChoice = ui.getFillingChoice();
            BreadType breadType = static_cast<BreadType>(breadChoice - 1);
            FillingType fillingType = static_cast<FillingType>(fillingChoice - 1);
            return std::make_unique<Sandwich>("Sandwich", breadType, fillingType);
        }
        default:
            return nullptr;
    }
}

std::unique_ptr<Drink> OrderHandler::createDrink(int choice) {
    UserInterface ui;
    switch (choice) {
        case 1: {
            int sugarAmount = ui.getSugarAmount();
            return std::make_unique<BlackCoffee>(sugarAmount);
        }
        case 2: {
            CoffeeType coffeeType = static_cast<CoffeeType>(ui.getCoffeeTypeChoice());
            MilkType milkType = static_cast<MilkType>(ui.getMilkTypeChoice());
            int sugarAmount = ui.getSugarAmount();
            return std::make_unique<WhiteCoffee>(coffeeType, milkType, sugarAmount);
        }
        case 3: {
            std::string teaType = ui.getTeaType();
            int sugarAmount = ui.getSugarAmount();
            return std::make_unique<Tea>(teaType, sugarAmount);
        }
        default:
            return nullptr;
    }
}