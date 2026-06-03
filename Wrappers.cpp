#include "Wrappers.h"

CoffeeShopWrapper::CoffeeShopWrapper( CoffeeShop* ptr ) : ptrToCoffeeShop( ptr ) { }
CoffeeShopWrapper::~CoffeeShopWrapper()
{
    delete ptrToCoffeeShop;         // safe to delete a nullptr
}

FitnessTrackerWrapper::FitnessTrackerWrapper( FitnessTracker* ptr ) : ptrToFitnessTracker( ptr ) { }
FitnessTrackerWrapper::~FitnessTrackerWrapper()
{
    delete ptrToFitnessTracker;         // safe to delete a nullptr
}

ComputerWrapper::ComputerWrapper( Computer* ptr ) : ptrToComputer( ptr ) { }
ComputerWrapper::~ComputerWrapper()
{
    delete ptrToComputer;         // safe to delete a nullptr
}

AudioInterfaceWrapper::AudioInterfaceWrapper( AudioInterface* ptr ) : ptrToAudioInterface( ptr ) { }
AudioInterfaceWrapper::~AudioInterfaceWrapper()
{
    delete ptrToAudioInterface;         // safe to delete a nullptr
}

StudioMonitorsWrapper::StudioMonitorsWrapper( StudioMonitors* ptr ) : ptrToStudioMonitors( ptr ) { }
StudioMonitorsWrapper::~StudioMonitorsWrapper()
{
    delete ptrToStudioMonitors;         // safe to delete a nullptr
}

MidiKeyboardWrapper::MidiKeyboardWrapper( MidiKeyboard* ptr ) : ptrToMidiKeyboard( ptr ) { }
MidiKeyboardWrapper::~MidiKeyboardWrapper()
{
    delete ptrToMidiKeyboard;         // safe to delete a nullptr
}

MicrophoneWrapper::MicrophoneWrapper( Microphone* ptr ) : ptrToMicrophone( ptr ) { }
MicrophoneWrapper::~MicrophoneWrapper()
{
    delete ptrToMicrophone;         // safe to delete a nullptr
}

MusicStudioComputerSetupWrapper::MusicStudioComputerSetupWrapper( MusicStudioComputerSetup* ptr ) : ptrToMusicStudioComputerSetup( ptr ) { }
MusicStudioComputerSetupWrapper::~MusicStudioComputerSetupWrapper()
{
    delete ptrToMusicStudioComputerSetup;         // safe to delete a nullptr
}

RecordingSessionWrapper::RecordingSessionWrapper( RecordingSession* ptr ) : ptrToRecordingSession( ptr ) { }
RecordingSessionWrapper::~RecordingSessionWrapper()
{
    delete ptrToRecordingSession;         // safe to delete a nullptr
}

MixingStudioWrapper::MixingStudioWrapper( MixingStudio* ptr ) : ptrToMixingStudio( ptr ) { }
MixingStudioWrapper::~MixingStudioWrapper()
{
    delete ptrToMixingStudio;         // safe to delete a nullptr
}
