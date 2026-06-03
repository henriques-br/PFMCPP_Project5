#pragma once
#include "Computer.h"
#include "AudioInterface.h"
#include "StudioMonitors.h"
#include "MidiKeyboard.h"
#include "Microphone.h"
#include "LeakedObjectDetector.h"

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
    
    void recordMusic(const std::string& projectName) const;
    void editAudioTrack(const std::string& trackName) const;
    void playVirtualInstrument(const std::string& instrumentName) const;
    void runRecordingSessions(const int& numOfSessions);
    
    JUCE_LEAK_DETECTOR(MusicStudioComputerSetup)
};
