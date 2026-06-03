#include "FitnessTracker.h"

FitnessTracker::WorkoutSession::WorkoutSession():
    workoutType("Walking"),
    workoutDurationInMinutes(55),
    isGpsTrackingEnabled(false)
{
 std::cout << "WorkoutSession being constructed!" << std::endl;
}

FitnessTracker::WorkoutSession::~WorkoutSession()
{
    std::cout << "WorkoutSession being destructed!" << std::endl;
}

void FitnessTracker::WorkoutSession::startWorkout() const
{
    std::cout << "Starting " << workoutType << " workout\n";
}

void FitnessTracker::WorkoutSession::pauseWorkout() const
{
    std::cout << "Pausing " << workoutType << " workout\n";
}

bool FitnessTracker::WorkoutSession::endWorkout() const
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

FitnessTracker::~FitnessTracker()
{
    std::cout << "FitnessTracker being destructed!" << std::endl;
}

void FitnessTracker::simulateStepGoal(const int& targetSteps, const int& stepsAddedPerLoop)
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

void FitnessTracker::trackWorkout(const WorkoutSession& curWorkoutSession) const
{
    std::cout << "Tracking workout type: " << curWorkoutSession.workoutType << "\n";

    std::cout << "Workout duration: " << curWorkoutSession.workoutDurationInMinutes << " minutes\n";
}

void FitnessTracker::displayNotification(std::string notificationMessage) const
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

void FitnessTracker::printFitnessTrackerInfo() const
{
    std::cout << "Battery Level: " << this->batteryPercentage << '\n';
    std::cout << "Steps Recorded: " << this->numOfStepsRecorded << '\n';
    std::cout << "Heart Rate: " << this->heartRateValue << '\n';
}
