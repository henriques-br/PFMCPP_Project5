#include "CoffeeShop.h"

CoffeeShop::CoffeeMachine::CoffeeMachine() :
    machineModelName("Perfect Brew"),
    waterTankCapacityInLiters(3.2f),
    numOfEspressoShotsMadeToday(0),
    machineTemperatureInCelsius(92.0),
    isSteamWandEnabled(true)
{
    std::cout << "CoffeeMachine constructed!\n";
}

CoffeeShop::CoffeeMachine::~CoffeeMachine()
{
    std::cout << "CoffeeMachine destructed!\n";
}

void CoffeeShop::CoffeeMachine::makeEspresso(const int& numOfShots)
{
    numOfEspressoShotsMadeToday += numOfShots;
    std::cout << "Machine Model: " << machineModelName << '\n';
    std::cout << "Water Tank Capacity: " << waterTankCapacityInLiters << " liters\n\n";

    std::cout << "Making " << numOfShots << " " << (numOfShots == 1 ? "cup" : "cups") << " espresso shots\n";
}

void CoffeeShop::CoffeeMachine::steamMilk(const float& milkAmountInMl) const
{
    std::cout << "Steaming " << milkAmountInMl << " ml of milk\n";
}

bool CoffeeShop::CoffeeMachine::cleanMachine() const
{
    std::cout << "Cleaning coffee machine\n";

    return true;
}

CoffeeShop::CoffeeShop(): numOfCoffeeMachines(6), numOfEmployees(9)
{
    std::cout << "CoffeeShop being constructed!" << std::endl;
}

CoffeeShop::~CoffeeShop()
{
    std::cout << "CoffeeShop being destructed!\n";
}

void CoffeeShop::brewCoffee(CoffeeMachine& activeCoffeeMachine, const int& numOfCups) const
{
    activeCoffeeMachine.makeEspresso(numOfCups);

    std::cout << "Brewing " << numOfCups << " cups of coffee\n";
    std::cout << "Shop Name: " << shopName << '\n';
    std::cout << "Employees: " << numOfEmployees << '\n';
    std::cout << "Coffee Machines: " << numOfCoffeeMachines << "\n\n";
}

void CoffeeShop::serveCustomers(int numOfCustomers) const
{
    std::cout << "Serving " << numOfCustomers << " customers\n";
}

void CoffeeShop::cleanTables(int numOfTables) const
{
    std::cout << "Cleaning " << numOfTables << " tables\n";
}

void CoffeeShop::restockCoffeeBeans(const float& amountToAdd, float maxStorageAmount)
{
    std::cout << "Restocking Coffee Beans\n";
    std::cout << "Amount in stock " << amountOfCoffeBeanInStorage << " Amount to add " << amountToAdd << " Max storage " << maxStorageAmount << "\n";
    while (amountOfCoffeBeanInStorage < maxStorageAmount)
    {
        amountOfCoffeBeanInStorage += amountToAdd;
        if (amountOfCoffeBeanInStorage >= maxStorageAmount)
        {
            std::cout << "Cannot add more beans.\n";
            std::cout << "Storage would exceed maximum capacity.\n";
            return;
        }
        else
        {
            std::cout << "Current coffee bean storage: " << amountOfCoffeBeanInStorage << " kg\n" ;
        }
    }
}

void CoffeeShop::printCoffeeShopInfo() const
{
    std::cout << "Shop Name: " << this->shopName << '\n';
    std::cout << "Employees: " << this->numOfEmployees << '\n';
    std::cout << "Coffee Machines: " << this->numOfCoffeeMachines << "\n";
}
