#pragma once
#include "Computer.h"
#include "StudioMonitors.h"
#include "MidiKeyboard.h"
#include "LeakedObjectDetector.h"

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

    void mixSong(const std::string& songName) const;
    void processMixSessions(const int& numOfSessions);
    void printMixingStudioInfo() const;
    
    JUCE_LEAK_DETECTOR(MixingStudio)
};
