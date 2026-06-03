#pragma once
#include "CoffeeShop.h"
#include "FitnessTracker.h"
#include "Computer.h"
#include "AudioInterface.h"
#include "StudioMonitors.h"
#include "MidiKeyboard.h"
#include "Microphone.h"
#include "MusicStudioComputerSetup.h"
#include "RecordingSession.h"
#include "MixingStudio.h"

struct CoffeeShopWrapper
{
    CoffeeShop* ptrToCoffeeShop = nullptr;

    CoffeeShopWrapper( CoffeeShop* ptr );
    ~CoffeeShopWrapper();
};

struct FitnessTrackerWrapper
{
    FitnessTrackerWrapper( FitnessTracker* ptr );
    ~FitnessTrackerWrapper();

    FitnessTracker* ptrToFitnessTracker = nullptr;
};

struct ComputerWrapper
{
    ComputerWrapper( Computer* ptr );
    ~ComputerWrapper();

    Computer* ptrToComputer = nullptr;
};

struct AudioInterfaceWrapper
{
    AudioInterfaceWrapper( AudioInterface* ptr );
    ~AudioInterfaceWrapper();

    AudioInterface* ptrToAudioInterface = nullptr;
};

struct StudioMonitorsWrapper
{
    StudioMonitorsWrapper( StudioMonitors* ptr );
    ~StudioMonitorsWrapper();

    StudioMonitors* ptrToStudioMonitors = nullptr;
};

struct MidiKeyboardWrapper
{
    MidiKeyboardWrapper( MidiKeyboard* ptr );
    ~MidiKeyboardWrapper();

    MidiKeyboard* ptrToMidiKeyboard = nullptr;
};

struct MicrophoneWrapper
{
    MicrophoneWrapper( Microphone* ptr );
    ~MicrophoneWrapper();

    Microphone* ptrToMicrophone = nullptr;
};

struct MusicStudioComputerSetupWrapper
{
    MusicStudioComputerSetupWrapper( MusicStudioComputerSetup* ptr );
    ~MusicStudioComputerSetupWrapper();

    MusicStudioComputerSetup* ptrToMusicStudioComputerSetup = nullptr;
};

struct RecordingSessionWrapper
{
    RecordingSessionWrapper( RecordingSession* ptr );
    ~RecordingSessionWrapper();

    RecordingSession* ptrToRecordingSession = nullptr;
};

struct MixingStudioWrapper
{
    MixingStudioWrapper( MixingStudio* ptr );
    ~MixingStudioWrapper();
    
    MixingStudio* ptrToMixingStudio = nullptr;
};
