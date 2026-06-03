#pragma once
#include "LeakedObjectDetector.h"

struct MidiKeyboard
{
    int numOfKeys = 88;
    int octaveRange = 7;
    bool isVelocitySensitivityEnabled;
    int numOfControlKnobs = 12;
    std::string usbConnectionType;

    MidiKeyboard();
    ~MidiKeyboard();
    
    void sendMidiNotes(const int& midiNoteNumber) const;
    void controlVirtualInstrument(const std::string& instrumentName) const;
    void adjustPluginParameter(const std::string& parameterName, const float& parameterValue) const;
    void playNotes(const int& numOfNotes) const;
    
    JUCE_LEAK_DETECTOR(MidiKeyboard)
};
