#pragma once
#include "LeakedObjectDetector.h"

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
    ~FitnessTracker();
       
    struct WorkoutSession
    {
        std::string workoutType;
        int workoutDurationInMinutes;
        double caloriesBurned = 520.5;
        int averageHeartRate = 138;
        bool isGpsTrackingEnabled;

        WorkoutSession();
        ~WorkoutSession();
        
        void startWorkout() const;
        void pauseWorkout() const;
        bool endWorkout() const;
    };
    
    void trackWorkout(const WorkoutSession& curWorkoutSession) const;
    void displayNotification(std::string notificationMessage) const;
    double monitorSleep(int hoursSlept);
    void simulateStepGoal(const int& targetSteps, const int& stepsAddedPerLoop);
    void printFitnessTrackerInfo() const;
    
    WorkoutSession currentWorkoutSession;
    JUCE_LEAK_DETECTOR(FitnessTracker)
};
