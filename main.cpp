/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
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

        void makeEspresso(int numOfShots);
        void steamMilk(float milkAmountInMl);
        bool cleanMachine();
    };
    
    void brewCoffee(CoffeeMachine activeCoffeeMachine, int numOfCups);
    void serveCustomers(int numOfCustomers);
    void cleanTables(int numOfTables);
    void restockCoffeeBeans(float amountToAdd, float maxStorageAmount);
    void printCoffeeShopInfo();
    
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

CoffeeShop::CoffeeMachine::~CoffeeMachine()
{
    std::cout << "CoffeeMachine destructed!\n";
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

CoffeeShop::~CoffeeShop()
{
    std::cout << "CoffeeShop being destructed!\n";
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

void CoffeeShop::printCoffeeShopInfo()
{
    std::cout << "Shop Name: " << this->shopName << '\n';
    std::cout << "Employees: " << this->numOfEmployees << '\n';
    std::cout << "Coffee Machines: " << this->numOfCoffeeMachines << "\n";
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

FitnessTracker::WorkoutSession::~WorkoutSession()
{
    std::cout << "WorkoutSession being destructed!" << std::endl;
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

FitnessTracker::~FitnessTracker()
{
    std::cout << "FitnessTracker being destructed!" << std::endl;
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
struct Computer
{
    double cpuSpeedInGhz;
    int amountRamInGb;
    int storageSizeInGb = 8000;
    std::string operatingSystemName;
    int numOfUsbPorts = 8;

    Computer();
    ~Computer();
       
    void runAudioSoftware(std::string softwareName);
    void saveProjectFile(std::string projectName);
    int processAudioPlugins(int numOfPlugins);
    void allocateRamToPlugins(int ramIncreaseAmount);
};

Computer::Computer():
    cpuSpeedInGhz(4),
    amountRamInGb(128),
    operatingSystemName("MacOS Tahoe")
{
    std::cout << "Computer being constructed!" << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer being destructed!" << std::endl;
}

void Computer::runAudioSoftware(std::string softwareName)
{
    std::cout << "Running audio software " << softwareName << "\n";
    std::cout << "Operating System Name " << operatingSystemName << "\n";
}

void Computer::saveProjectFile(std::string projectName)
{
    std::cout << "Saving project file " << projectName << "\n";
}

int Computer::processAudioPlugins(int numOfPlugins)
{
    std::cout << "Processing " << numOfPlugins << " audio plugins\n";

    return numOfPlugins;
}

void Computer::allocateRamToPlugins(int ramIncreaseAmount)
{
    for(int i = 0; i <= ramIncreaseAmount; i++)
    {
        std::cout << "Allocating RAM To Plugins " << i << "\n";
        if(i >= 16)
        {
            std::cout << "Maximum amount reached " << i << "\n";
            return;
        }
    }
    
    std::cout << "Maximum RAM capacity reached.\n";
}

struct AudioInterface
{
    int numOfInputChannels;
    int numOfOutputChannels;
    double sampleRateInKhz;
    bool isPhantomPowerEnabled = true;
    float headphoneOutputVolume = 45.5f;

    AudioInterface();
    ~AudioInterface();
       
    void convertAnalogToDigitalAudio();
    void sendAudioToStudioMonitors(float outputVolume);
    bool connectMicrophone(std::string microphoneName);
    void increaseHeadphoneVolume(float volumeIncreaseAmount, float maximumSafeVolume);
};

AudioInterface::AudioInterface():
    numOfInputChannels(26),
    numOfOutputChannels(20),
    sampleRateInKhz(48000)
{
    std::cout << "AudioInterface being constructed!" << std::endl;
}

AudioInterface::~AudioInterface()
{
    std::cout << "AudioInterface being destructed!" << std::endl;
}

void AudioInterface::convertAnalogToDigitalAudio()
{
    std::cout << "Converting analog audio to digital audio\n";
}

void AudioInterface::sendAudioToStudioMonitors(float outputVolume)
{
    headphoneOutputVolume = outputVolume;

    std::cout << "Sending audio to studio monitors at volume " << outputVolume << "\n";
}

bool AudioInterface::connectMicrophone(std::string microphoneName)
{
    std::cout << "Connecting microphone " << microphoneName << "\n";
    std::cout << "Number of Input Channels " << numOfInputChannels << "\n";
    std::cout << "Number of Output Channels " << numOfOutputChannels << "\n";

    return true;
}

void AudioInterface::increaseHeadphoneVolume(float volumeIncreaseAmount, float maximumSafeVolume)
{
    if (volumeIncreaseAmount <= 0.f)
    {
        std::cout << "Invalid volume increase amount\n";

        return;
    }

    std::cout << "Headphone output volume " << headphoneOutputVolume << "\n";
    while (headphoneOutputVolume < maximumSafeVolume)
    {
        if (headphoneOutputVolume + volumeIncreaseAmount > maximumSafeVolume)
        {
            std::cout << "Maximum safe volume would be exceeded.\n";

            return;
        }

        headphoneOutputVolume += volumeIncreaseAmount;

        std::cout << "Current headphone volume: " << headphoneOutputVolume << '\n';
    }

    std::cout << "Maximum headphone volume reached.\n";
}

struct StudioMonitors
{
    double speakerSizeInInches;
    int powerOutputsInWatts;
    float frequencyResponseRangeInHz;
    float volumeLevel = 45.f;
    double cabinetWidthInCm = 30;

    StudioMonitors();
    ~StudioMonitors();
    
    void playAudioPlayback(std::string audioFileName);
    void reproduceLowFrequencies();
    void monitorRecordingSession(int sessionDurationInMinutes);
    void increaseVolume(float volumeIncreaseAmount, float maximumSafeVolume);
};

StudioMonitors::StudioMonitors():
    speakerSizeInInches(10),
    powerOutputsInWatts(1200),
    frequencyResponseRangeInHz(250)
{
    std::cout << "StudioMonitors being constructed!" << std::endl;
}

StudioMonitors::~StudioMonitors()
{
    std::cout << "StudioMonitors being destructed!" << std::endl;
}

void StudioMonitors::playAudioPlayback(std::string audioFileName)
{
    std::cout << "Playing audio file " << audioFileName << "\n";
}

void StudioMonitors::reproduceLowFrequencies()
{
    std::cout << "Reproducing low frequencies\n";
}

void StudioMonitors::monitorRecordingSession(int sessionDurationInMinutes)
{
    std::cout << "Monitoring recording session for " << sessionDurationInMinutes << " minutes\n";
    std::cout << "Power Outputs In Watts " << powerOutputsInWatts << "\n";
    std::cout << "Frequency Response Range In Hz" << frequencyResponseRangeInHz << "\n";
}

void StudioMonitors::increaseVolume(float volumeIncreaseAmount, float maximumSafeVolume)
{
    if (volumeIncreaseAmount <= 0.f)
    {
        std::cout << "Invalid volume increase amount.\n";
        return;
    }

    while (volumeLevel < maximumSafeVolume)
    {
        volumeLevel += volumeIncreaseAmount;
        std::cout << "Current monitor volume: " << volumeLevel << '\n';
    }
    std::cout << "Maximum monitor volume reached\n";
}

struct MidiKeyboard
{
    int numOfKeys = 88;
    int octaveRange = 7;
    bool isVelocitySensitivityEnabled;
    int numOfControlKnobs = 12;
    std::string usbConnectionType;

    MidiKeyboard();
    ~MidiKeyboard();
    
    void sendMidiNotes(int midiNoteNumber);
    void controlVirtualInstrument(std::string instrumentName);
    void adjustPluginParameter(std::string parameterName, float parameterValue);
    void playNotes(int numOfNotes);
};

MidiKeyboard::MidiKeyboard():
    isVelocitySensitivityEnabled(true),
    usbConnectionType("USB-C")
{
    std::cout << "MidiKeyboard being constructed!" << std::endl;
}

MidiKeyboard::~MidiKeyboard()
{
    std::cout << "MidiKeyboard being destructed!" << std::endl;
}

void MidiKeyboard::sendMidiNotes(int midiNoteNumber)
{
    std::cout << "Sending MIDI note " << midiNoteNumber << "\n";
}

void MidiKeyboard::controlVirtualInstrument(std::string instrumentName)
{
    std::cout << "Controlling virtual instrument " << instrumentName << "\n";
    std::cout << "USB Connection Type " << usbConnectionType << "\n";
    std::cout << "Velocity Sensitivity Enabled " << (isVelocitySensitivityEnabled == 1 ? "TRUE" : "FALSE") << "\n";
}

void MidiKeyboard::adjustPluginParameter(std::string parameterName, float parameterValue)
{
    std::cout << "Adjusting parameter " << parameterName << " to " << parameterValue << "\n";
}

void MidiKeyboard::playNotes(int numOfNotes)
{
    std::cout << "\nPlaying MIDI notes...\n";

    for (int note = 1; note <= numOfNotes; ++note)
    {
        std::cout << "Playing note #" << note << '\n';

        if (note >= 5)
        {
            std::cout << "Stopping playback early.\n";
            return;
        }
    }
}

struct Microphone
{
    std::string microphoneType;
    float frequencyResponseRangeInHz = 80;
    double sensitivityLevel;
    double cableLenghtInMeters;
    int maximumSoundPressureLevelInDb = 12;

    Microphone();
    ~Microphone();
    
    void captureVocalRecording(std::string vocalistName);
    void recordAcousticInstrument(std::string instrumentName);
    bool reduceBackgroundNoise();
    void increaseSensitivity(double maxSensitivity);
};

Microphone::Microphone():
    microphoneType("Condenser"),
    sensitivityLevel(7),
    cableLenghtInMeters(5)
{
    std::cout << "Microphone being constructed!" << std::endl;
}

Microphone::~Microphone()
{
    std::cout << "Microphone being destructed!" << std::endl;
}

void Microphone::captureVocalRecording(std::string vocalistName)
{
    std::cout << "Capturing vocals for " << vocalistName << "\n";
    std::cout << "Micropphone Type" << microphoneType << "\n";
    std::cout << "Cable Lenght In Meters " << cableLenghtInMeters << "\n";
}

void Microphone::recordAcousticInstrument(std::string instrumentName)
{
    std::cout << "Recording acoustic instrument " << instrumentName << "\n";
}

bool Microphone::reduceBackgroundNoise()
{
    std::cout << "Reducing background noise\n";

    return true;
}

void Microphone::increaseSensitivity(double maxSensitivity)
{
    while (sensitivityLevel < maxSensitivity)
    {
        sensitivityLevel += 0.5;
        std::cout << "Current sensitivity level: " << sensitivityLevel << '\n';

        if (sensitivityLevel >= maxSensitivity)
        {
            std::cout << "Maximum sensitivity reached!\n";
            return;
        }
    }
}
struct MusicStudioComputerSetup
{
    Computer computer;
    AudioInterface audioInterface;
    StudioMonitors studioMonitors;
    MidiKeyboard midiKeyboard;
    Microphone microphone;
    int numOfProjectsCompleted = 0;
    
    MusicStudioComputerSetup();
    ~MusicStudioComputerSetup();
    
    void recordMusic(std::string projectName);
    void editAudioTrack(std::string trackName);
    void playVirtualInstrument(std::string instrumentName);
    void runRecordingSessions(int numOfSessions);
};

MusicStudioComputerSetup::MusicStudioComputerSetup()
{
    std::cout << "MusicStudioComputerSetup being constructed!" << std::endl;
}

MusicStudioComputerSetup::~MusicStudioComputerSetup()
{
    std::cout << "MusicStudioComputerSetup being destructed!" << std::endl;
}

void MusicStudioComputerSetup::recordMusic(std::string projectName)
{
    computer.runAudioSoftware(projectName);

    microphone.captureVocalRecording("Lead Vocalist");

    audioInterface.convertAnalogToDigitalAudio();

    std::cout << "Recording music project: " << projectName << "\n";
}

void MusicStudioComputerSetup::editAudioTrack(std::string trackName)
{
    computer.saveProjectFile(trackName);

    studioMonitors.monitorRecordingSession(60);

    std::cout << "Editing audio track: " << trackName << "\n";
}

void MusicStudioComputerSetup::playVirtualInstrument(std::string instrumentName)
{
    midiKeyboard.controlVirtualInstrument(instrumentName);

    studioMonitors.playAudioPlayback(instrumentName);

    std::cout << "Playing virtual instrument: " << instrumentName << "\n";
}

void MusicStudioComputerSetup::runRecordingSessions(int numOfSessions)
{
    std::cout << "\nRunning recording sessions...\n";

    for (int session = 1; session <= numOfSessions; ++session)
    {
        ++numOfProjectsCompleted;

        std::cout << "Completed recording session #" << session << " Projects completed: " << numOfProjectsCompleted << '\n';

        if (numOfProjectsCompleted >= 5)
        {
            std::cout << "Studio reached daily project limit.\n";
            return;
        }
    }
}

/*
 new UDT 4:
 with 2 member functions
 */
struct RecordingSession
{
    Computer computer;
    AudioInterface audioInterface;
    Microphone microphone;

    int sessionDurationInMinutes;
    int numOfTracksRecorded = 0;
    std::string sessionName = "Rock Session";

    RecordingSession();
    ~RecordingSession();

    void startSession(std::string vocalistName);
    void recordTracks(int numOfTracks);
};

RecordingSession::RecordingSession():
    sessionDurationInMinutes(120)
{
    std::cout << "RecordingSession being constructed!" << std::endl;
    
    computer.runAudioSoftware("Pro Tools");
    audioInterface.connectMicrophone("Shure SM7B");
    microphone.reduceBackgroundNoise();
}

RecordingSession::~RecordingSession()
{
    std::cout << "RecordingSession being destructed!" << std::endl;
    computer.saveProjectFile(sessionName);
    std::cout << "Final track count: " << numOfTracksRecorded << '\n';
}

void RecordingSession::startSession(std::string vocalistName)
{
    computer.runAudioSoftware("Logic Pro");

    audioInterface.convertAnalogToDigitalAudio();

    microphone.captureVocalRecording(vocalistName);

    std::cout << "Starting recording session: " << sessionName << "\n";
}

void RecordingSession::recordTracks(int numOfTracks)
{
    for (int trackNum = 1; trackNum <= numOfTracks; ++trackNum)
    {
        ++numOfTracksRecorded;

        std::cout << "Recording track #" << trackNum << '\n';

        if (numOfTracksRecorded >= 10)
        {
            std::cout << "Maximum number of tracks recorded\n";
            return;
        }
    }
}
/*
 new UDT 5:
 with 2 member functions
 */
struct MixingStudio
{
    Computer computer;
    StudioMonitors studioMonitors;
    MidiKeyboard midiKeyboard;

    int numOfMixesCompleted = 0;
    double sessionCpuUsagePercentage = 45.0;
    std::string mixingEngineerName = "Alex";

    MixingStudio();
    ~MixingStudio();

    void mixSong(std::string songName);
    void processMixSessions(int numOfSessions);
};

MixingStudio::MixingStudio()
{
    std::cout << "MixingStudio being constructed!" << std::endl;
    computer.allocateRamToPlugins(8);
    midiKeyboard.playNotes(3);
    studioMonitors.increaseVolume(2.f, 50.f);
}

MixingStudio::~MixingStudio()
{
    std::cout << "MixingStudio being destructed!" << std::endl;
    studioMonitors.playAudioPlayback("Final Mix Bounce.wav");
}

void MixingStudio::mixSong(std::string songName)
{
    computer.processAudioPlugins(25);

    midiKeyboard.controlVirtualInstrument("Synth Pad");

    studioMonitors.playAudioPlayback(songName);

    std::cout << "Mixing song: " << songName << '\n';
}

void MixingStudio::processMixSessions(int numOfSessions)
{
    for (int sessionNum = 1; sessionNum <= numOfSessions; ++sessionNum)
    {
        ++numOfMixesCompleted;

        std::cout << "Processing mix session #" << sessionNum << '\n';

        for (int plugin = 1; plugin <= 3; ++plugin)
        {
            std::cout << "Loading plugin #" << plugin << '\n';
        }

        if (numOfMixesCompleted >= 5)
        {
            std::cout << "Daily mixing limit reached\n";
            return;
        }
    }
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    std::cout << "=========== 1st UDT ===========" << std::endl;
    CoffeeShop coffeeShop;
    /*
    coffeeShop.serveCustomers(12);
    coffeeShop.cleanTables(5);
    coffeeShop.currentCoffeeMachine.makeEspresso(3);
    coffeeShop.currentCoffeeMachine.steamMilk(250.0f);
    coffeeShop.currentCoffeeMachine.cleanMachine();
    coffeeShop.brewCoffee(coffeeShop.currentCoffeeMachine, 10);
    coffeeShop.restockCoffeeBeans(8.f, 55.f);
    */
    
    std::cout << "Shop Name: " << coffeeShop.shopName << '\n';
    std::cout << "Employees: " << coffeeShop.numOfEmployees << '\n';
    std::cout << "Coffee Machines: " << coffeeShop.numOfCoffeeMachines << "\n";
    
    coffeeShop.printCoffeeShopInfo();
    
    std::cout << "=========== 2nd UDT with nested ===========" << std::endl;
    FitnessTracker fitnessTracker;
    fitnessTracker.currentWorkoutSession.startWorkout();
    fitnessTracker.trackWorkout(fitnessTracker.currentWorkoutSession);
    fitnessTracker.displayNotification("Goal reached");
    fitnessTracker.monitorSleep(8);
    fitnessTracker.currentWorkoutSession.pauseWorkout();
    fitnessTracker.currentWorkoutSession.endWorkout();
    fitnessTracker.simulateStepGoal(3000, 500);
    
    std::cout << "=========== 3rd UDT with nested ===========" << std::endl;
    MusicStudioComputerSetup setup;
    setup.recordMusic("New Album");
    setup.editAudioTrack("Lead Vocals");
    setup.playVirtualInstrument("Synth Pad");
    setup.runRecordingSessions(4);
    
    std::cout << "=========== 4th UDT with nested ===========" << std::endl;
    RecordingSession recordingSession;
    recordingSession.startSession("Another Day");
    recordingSession.recordTracks(6);
    
    std::cout << "=========== 5th UDT with nested ===========" << std::endl;
    MixingStudio mixingStudio;
    mixingStudio.mixSong("Thunder");
    mixingStudio.processMixSessions(4);
    
    std::cout << "good to go!" << std::endl;
}
