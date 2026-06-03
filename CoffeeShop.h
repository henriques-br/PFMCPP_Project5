#pragma once
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */
struct CoffeeShop
{
    int numOfCoffeeMachines;
    int numOfEmployees;
    float amountOfCoffeBeanInStorage = 25.f;
    double dailyProfitAmount =  1500;
    std::string shopName = "Prenda Cafe";

    CoffeeShop();
    ~CoffeeShop();

    struct CoffeeMachine
    {
        std::string machineModelName;
        float waterTankCapacityInLiters;
        int numOfEspressoShotsMadeToday = 120;
        double machineTemperatureInCelsius;
        bool isSteamWandEnabled = true;

        CoffeeMachine();
        ~CoffeeMachine();

        void makeEspresso(const int& numOfShots);
        void steamMilk(const float& milkAmountInMl) const;
        bool cleanMachine() const;
    };
    
    void brewCoffee(CoffeeMachine& activeCoffeeMachine, const int& numOfCups) const;
    void serveCustomers(int numOfCustomers) const;
    void cleanTables(int numOfTables) const;
    void restockCoffeeBeans(const float& amountToAdd, float maxStorageAmount);
    void printCoffeeShopInfo() const;
    
    CoffeeMachine currentCoffeeMachine;
    JUCE_LEAK_DETECTOR(CoffeeShop)
};
