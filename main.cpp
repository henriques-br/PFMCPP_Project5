/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

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

    struct CoffeeMachine
    {
        std::string machineModelName;
        float waterTankCapacityInLiters;
        int numOfEspressoShotsMadeToday = 120;
        double machineTemperatureInCelsius;
        bool isSteamWandEnabled = true;

        CoffeeMachine();

        void makeEspresso(int numOfShots);
        void steamMilk(float milkAmountInMl);
        bool cleanMachine();
    };
    
    void brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups);
    void serveCustomers(int numOfCustomers);
    void cleanTables(int numOfTables);
    void restockCoffeeBeans(float amountToAdd, float maxStorageAmount);
    
    CoffeeMachine currentCoffeeMachine;
};

CoffeeShop::CoffeeMachine::CoffeeMachine() :
    machineModelName("Perfect Brew"),
    waterTankCapacityInLiters(3.2f),
    numOfEspressoShotsMadeToday(0),
    machineTemperatureInCelsius(92.0),
    isSteamWandEnabled(true)
{
    std::cout << "CoffeeMachine constructed!\n";
}

void CoffeeShop::CoffeeMachine::makeEspresso(int numOfShots)
{
    numOfEspressoShotsMadeToday += numOfShots;
    std::cout << "Machine Model: " << machineModelName << '\n';
    std::cout << "Water Tank Capacity: " << waterTankCapacityInLiters << " liters\n\n";

    std::cout << "Making " << numOfShots << " " << (numOfShots == 1 ? "cup" : "cups") << " espresso shots\n";
}

void CoffeeShop::CoffeeMachine::steamMilk(float milkAmountInMl)
{
    std::cout << "Steaming " << milkAmountInMl << " ml of milk\n";
}

bool CoffeeShop::CoffeeMachine::cleanMachine()
{
    std::cout << "Cleaning coffee machine\n";

    return true;
}

CoffeeShop::CoffeeShop(): numOfCoffeeMachines(6), numOfEmployees(9)
{
    std::cout << "CoffeeShop being constructed!" << std::endl;
}

void CoffeeShop::brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups)
{
    activeCoffeeMachine.makeEspresso(numOfCups);

    std::cout << "Brewing " << numOfCups << " cups of coffee\n";
    std::cout << "Shop Name: " << shopName << '\n';
    std::cout << "Employees: " << numOfEmployees << '\n';
    std::cout << "Coffee Machines: " << numOfCoffeeMachines << "\n\n";
}

void CoffeeShop::serveCustomers(int numOfCustomers)
{
    std::cout << "Serving " << numOfCustomers << " customers\n";
}

void CoffeeShop::cleanTables(int numOfTables)
{
    std::cout << "Cleaning " << numOfTables << " tables\n";
}

void CoffeeShop::restockCoffeeBeans(float amountToAdd, float maxStorageAmount)
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
/*
 copied UDT 2:
 */
struct FitnessTracker
{
    float batteryPercentage;
    int numOfStepsRecorded;
    int heartRateValue = 145;
    std::string deviceColor;
    double dailyCalorieCount = 645;

    FitnessTracker();
       
    struct WorkoutSession
    {
        std::string workoutType;
        int workoutDurationInMinutes;
        double caloriesBurned = 520.5;
        int averageHeartRate = 138;
        bool isGpsTrackingEnabled;

        WorkoutSession();

        void startWorkout();
        void pauseWorkout();
        bool endWorkout();
    };
    
    void trackWorkout(WorkoutSession curWorkoutSession);
    void displayNotification(std::string notificationMessage);
    double monitorSleep(int hoursSlept);
    void simulateStepGoal(int targetSteps, int stepsAddedPerLoop);
    
    WorkoutSession currentWorkoutSession;
};

FitnessTracker::WorkoutSession::WorkoutSession():
    workoutType("Walking"),
    workoutDurationInMinutes(55),
    isGpsTrackingEnabled(false)
{
 std::cout << "WorkoutSession being constructed!" << std::endl;
}

void FitnessTracker::WorkoutSession::startWorkout()
{
    std::cout << "Starting " << workoutType << " workout\n";
}

void FitnessTracker::WorkoutSession::pauseWorkout()
{
    std::cout << "Pausing " << workoutType << " workout\n";
}

bool FitnessTracker::WorkoutSession::endWorkout()
{
    std::cout << "Ending " << workoutType << " workout\n";

    return true;
}

FitnessTracker::FitnessTracker():
    batteryPercentage(75.f),
    numOfStepsRecorded(127),
    deviceColor("Black")
{
    std::cout << "FitnessTracker being constructed!" << std::endl;
}

void FitnessTracker::simulateStepGoal(int targetSteps, int stepsAddedPerLoop)
{
    std::cout << "Simulating Step Goal\n";

    while (numOfStepsRecorded < targetSteps)
    {
        if (numOfStepsRecorded + stepsAddedPerLoop > targetSteps)
        {
            std::cout << "Cannot add more steps.\n";
            std::cout << "Step count would exceed target goal.\n";

            return;
        }

        numOfStepsRecorded += stepsAddedPerLoop;

        std::cout << "Current steps recorded: " << numOfStepsRecorded << '\n';
    }

    std::cout << "Daily step goal reached!\n";
}

void FitnessTracker::trackWorkout(WorkoutSession curWorkoutSession)
{
    std::cout << "Tracking workout type: " << curWorkoutSession.workoutType << "\n";

    std::cout << "Workout duration: " << curWorkoutSession.workoutDurationInMinutes << " minutes\n";
}

void FitnessTracker::displayNotification(std::string notificationMessage)
{
    std::cout << "Notification: " << notificationMessage << "\n";
    std::cout << "Number of steps recorded: " << numOfStepsRecorded << "\n";
    std::cout << "Battery Level: " << batteryPercentage << "\n";
}


double FitnessTracker::monitorSleep(int hoursSlept)
{
    double sleepQualityScore = hoursSlept * 10.0;

    std::cout << "User slept for " << hoursSlept << " hours\n";

    return sleepQualityScore;
}

/*
 copied UDT 3:
 */

/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
