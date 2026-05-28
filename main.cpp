/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
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

        void makeEspresso(int numOfShots);
        void steamMilk(float milkAmountInMl) const;
        bool cleanMachine() const;
    };
    
    void brewCoffee(CoffeeMachine& activeCoffeeMachine, int numOfCups);
    void serveCustomers(int numOfCustomers) const;
    void cleanTables(int numOfTables) const;
    void restockCoffeeBeans(float amountToAdd, float maxStorageAmount);
    void printCoffeeShopInfo() const;
    
    CoffeeMachine currentCoffeeMachine;
    JUCE_LEAK_DETECTOR(CoffeeShop)
};

struct CoffeeShopWrapper
{
    CoffeeShopWrapper( CoffeeShop* ptr ) : ptrToCoffeeShop( ptr ) { }
    ~CoffeeShopWrapper()
    {
        delete ptrToCoffeeShop;         // safe to delete a nullptr
    }

    CoffeeShop* ptrToCoffeeShop = nullptr;
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

void CoffeeShop::CoffeeMachine::steamMilk(float milkAmountInMl) const
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

void CoffeeShop::brewCoffee(CoffeeMachine& activeCoffeeMachine, int numOfCups)
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

void CoffeeShop::printCoffeeShopInfo() const
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
        
        void startWorkout() const;
        void pauseWorkout() const;
        bool endWorkout();
    };
    
    void trackWorkout(const WorkoutSession& curWorkoutSession) const;
    void displayNotification(std::string notificationMessage) const;
    double monitorSleep(int hoursSlept);
    void simulateStepGoal(int targetSteps, int stepsAddedPerLoop);
    void printFitnessTrackerInfo() const;
    
    WorkoutSession currentWorkoutSession;
    JUCE_LEAK_DETECTOR(FitnessTracker)
};

struct FitnessTrackerWrapper
{
    FitnessTrackerWrapper( FitnessTracker* ptr ) : ptrToFitnessTracker( ptr ) { }
    ~FitnessTrackerWrapper()
    {
        delete ptrToFitnessTracker;         // safe to delete a nullptr
    }

    FitnessTracker* ptrToFitnessTracker = nullptr;
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

void FitnessTracker::WorkoutSession::startWorkout() const
{
    std::cout << "Starting " << workoutType << " workout\n";
}

void FitnessTracker::WorkoutSession::pauseWorkout() const
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
    void printComputerInfo();
    
    JUCE_LEAK_DETECTOR(Computer)
};

struct ComputerWrapper
{
    ComputerWrapper( Computer* ptr ) : ptrToComputer( ptr ) { }
    ~ComputerWrapper()
    {
        delete ptrToComputer;         // safe to delete a nullptr
    }

    Computer* ptrToComputer = nullptr;
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

void Computer::printComputerInfo()
{
    std::cout << "CPU Speed: " << this->cpuSpeedInGhz << '\n';
    std::cout << "RAM Amount: " << this->amountRamInGb << '\n';
    std::cout << "Operating System: " << this->operatingSystemName << '\n';
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
    
    JUCE_LEAK_DETECTOR(AudioInterface)
};

struct AudioInterfaceWrapper
{
    AudioInterfaceWrapper( AudioInterface* ptr ) : ptrToAudioInterface( ptr ) { }
    ~AudioInterfaceWrapper()
    {
        delete ptrToAudioInterface;         // safe to delete a nullptr
    }

    AudioInterface* ptrToAudioInterface = nullptr;
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
    
    JUCE_LEAK_DETECTOR(StudioMonitors)
};

struct StudioMonitorsWrapper
{
    StudioMonitorsWrapper( StudioMonitors* ptr ) : ptrToStudioMonitors( ptr ) { }
    ~StudioMonitorsWrapper()
    {
        delete ptrToStudioMonitors;         // safe to delete a nullptr
    }

    StudioMonitors* ptrToStudioMonitors = nullptr;
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
    
    JUCE_LEAK_DETECTOR(MidiKeyboard)
};

struct MidiKeyboardWrapper
{
    MidiKeyboardWrapper( MidiKeyboard* ptr ) : ptrToMidiKeyboard( ptr ) { }
    ~MidiKeyboardWrapper()
    {
        delete ptrToMidiKeyboard;         // safe to delete a nullptr
    }

    MidiKeyboard* ptrToMidiKeyboard = nullptr;
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
    
    JUCE_LEAK_DETECTOR(Microphone)
};

struct MicrophoneWrapper
{
    MicrophoneWrapper( Microphone* ptr ) : ptrToMicrophone( ptr ) { }
    ~MicrophoneWrapper()
    {
        delete ptrToMicrophone;         // safe to delete a nullptr
    }

    Microphone* ptrToMicrophone = nullptr;
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
    
    JUCE_LEAK_DETECTOR(MusicStudioComputerSetup)
};

struct MusicStudioComputerSetupWrapper
{
    MusicStudioComputerSetupWrapper( MusicStudioComputerSetup* ptr ) : ptrToMusicStudioComputerSetup( ptr ) { }
    ~MusicStudioComputerSetupWrapper()
    {
        delete ptrToMusicStudioComputerSetup;         // safe to delete a nullptr
    }

    MusicStudioComputerSetup* ptrToMusicStudioComputerSetup = nullptr;
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
    void printRecordingSessionInfo();
    
    JUCE_LEAK_DETECTOR(RecordingSession)
};

struct RecordingSessionWrapper
{
    RecordingSessionWrapper( RecordingSession* ptr ) : ptrToRecordingSession( ptr ) { }
    ~RecordingSessionWrapper()
    {
        delete ptrToRecordingSession;         // safe to delete a nullptr
    }

    RecordingSession* ptrToRecordingSession = nullptr;
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

void RecordingSession::printRecordingSessionInfo()
{
    std::cout << "Session Name: " << this->sessionName << '\n';
    std::cout << "Session Duration: " << this->sessionDurationInMinutes << '\n';
    std::cout << "Tracks Recorded: " << this->numOfTracksRecorded << '\n';
    std::cout << "Computer Operating System: " << this->computer.operatingSystemName << '\n';
    std::cout << "Microphone Type: " << this->microphone.microphoneType << '\n';
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
    void printMixingStudioInfo();
    
    JUCE_LEAK_DETECTOR(MixingStudio)
};

struct MixingStudioWrapper
{
    MixingStudioWrapper( MixingStudio* ptr ) : ptrToMixingStudio( ptr ) { }
    ~MixingStudioWrapper()
    {
        delete ptrToMixingStudio;         // safe to delete a nullptr
    }

    MixingStudio* ptrToMixingStudio = nullptr;
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

void MixingStudio::printMixingStudioInfo()
{
    std::cout << "Mixing Engineer: " << this->mixingEngineerName << '\n';
    std::cout << "Mixes Completed: " << this->numOfMixesCompleted << '\n';
    std::cout << "CPU Usage Percentage: " << this->sessionCpuUsagePercentage << '\n';
    std::cout << "Computer RAM: " << this->computer.amountRamInGb << '\n';
    std::cout << "Monitor Volume: " << this->studioMonitors.volumeLevel << '\n';
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
    //CoffeeShop coffeeShop;
    CoffeeShopWrapper coffeeShop( new CoffeeShop() );
    
    /*
    coffeeShop.serveCustomers(12);
    coffeeShop.cleanTables(5);
    coffeeShop.currentCoffeeMachine.makeEspresso(3);
    coffeeShop.currentCoffeeMachine.steamMilk(250.0f);
    coffeeShop.currentCoffeeMachine.cleanMachine();
    coffeeShop.brewCoffee(coffeeShop.currentCoffeeMachine, 10);
    coffeeShop.restockCoffeeBeans(8.f, 55.f);
    */
    
    std::cout << "Shop Name: " << coffeeShop.ptrToCoffeeShop->shopName << '\n';
    std::cout << "Employees: " << coffeeShop.ptrToCoffeeShop->numOfEmployees << '\n';
    std::cout << "Coffee Machines: " << coffeeShop.ptrToCoffeeShop->numOfCoffeeMachines << "\n";
    
    coffeeShop.ptrToCoffeeShop->printCoffeeShopInfo();
    
    std::cout << "=========== 2nd UDT with nested ===========" << std::endl;
    //FitnessTracker fitnessTracker;
    FitnessTrackerWrapper fitnessTracker( new FitnessTracker() );

    /*
    fitnessTracker.currentWorkoutSession.startWorkout();
    fitnessTracker.trackWorkout(fitnessTracker.currentWorkoutSession);
    fitnessTracker.displayNotification("Goal reached");
    fitnessTracker.monitorSleep(8);
    fitnessTracker.currentWorkoutSession.pauseWorkout();
    fitnessTracker.currentWorkoutSession.endWorkout();
    fitnessTracker.simulateStepGoal(3000, 500);
    */
    std::cout << "Battery Level: " << fitnessTracker.ptrToFitnessTracker->batteryPercentage << '\n';
    std::cout << "Steps Recorded: " << fitnessTracker.ptrToFitnessTracker->numOfStepsRecorded << '\n';
    std::cout << "Heart Rate: " << fitnessTracker.ptrToFitnessTracker->heartRateValue << '\n';

    fitnessTracker.ptrToFitnessTracker->printFitnessTrackerInfo();

    std::cout << "=========== 3rd UDT with nested ===========" << std::endl;
    //MusicStudioComputerSetup setup;
    MusicStudioComputerSetupWrapper setup( new MusicStudioComputerSetup() );
    /*
    setup.recordMusic("New Album");
    setup.editAudioTrack("Lead Vocals");
    setup.playVirtualInstrument("Synth Pad");
    setup.runRecordingSessions(4);
    */

    std::cout << "CPU Speed: " << setup.ptrToMusicStudioComputerSetup->computer.cpuSpeedInGhz << '\n';
    std::cout << "RAM Amount: " << setup.ptrToMusicStudioComputerSetup->computer.amountRamInGb << '\n';
    std::cout << "Operating System: " << setup.ptrToMusicStudioComputerSetup->computer.operatingSystemName << '\n';

    setup.ptrToMusicStudioComputerSetup->computer.printComputerInfo();
  
    std::cout << "=========== 4th UDT with nested ===========" << std::endl;
    //RecordingSession recordingSession;
    RecordingSessionWrapper recordingSession( new RecordingSession() );
  
    /*
    recordingSession.startSession("Another Day");
    recordingSession.recordTracks(6);
    */
    std::cout << "Session Name: " << recordingSession.ptrToRecordingSession->sessionName << '\n';
    std::cout << "Session Duration: " << recordingSession.ptrToRecordingSession->sessionDurationInMinutes << '\n';
    std::cout << "Tracks Recorded: " << recordingSession.ptrToRecordingSession->numOfTracksRecorded << '\n';
    std::cout << "Computer Operating System: " << recordingSession.ptrToRecordingSession->computer.operatingSystemName << '\n';
    std::cout << "Microphone Type: " << recordingSession.ptrToRecordingSession->microphone.microphoneType << '\n';

    recordingSession.ptrToRecordingSession->printRecordingSessionInfo();
  
    std::cout << "=========== 5th UDT with nested ===========" << std::endl;
    //MixingStudio mixingStudio;
    MixingStudioWrapper mixingStudio( new MixingStudio() );

    /*
    mixingStudio.mixSong("Thunder");
    mixingStudio.processMixSessions(4);
    */
    std::cout << "Mixing Engineer: " << mixingStudio.ptrToMixingStudio->mixingEngineerName << '\n';
    std::cout << "Mixes Completed: " << mixingStudio.ptrToMixingStudio->numOfMixesCompleted << '\n';
    std::cout << "CPU Usage Percentage: " << mixingStudio.ptrToMixingStudio->sessionCpuUsagePercentage << '\n';
    std::cout << "Computer RAM: " << mixingStudio.ptrToMixingStudio->computer.amountRamInGb << '\n';
    std::cout << "Monitor Volume: " << mixingStudio.ptrToMixingStudio->studioMonitors.volumeLevel << '\n';
    
    mixingStudio.ptrToMixingStudio->printMixingStudioInfo();
   
    std::cout << "good to go!" << std::endl;
}
