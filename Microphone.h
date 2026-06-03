#pragma once
#include "LeakedObjectDetector.h"

struct Microphone
{
    std::string microphoneType;
    float frequencyResponseRangeInHz = 80;
    double sensitivityLevel;
    double cableLenghtInMeters;
    int maximumSoundPressureLevelInDb = 12;

    Microphone();
    ~Microphone();
    
    void captureVocalRecording(const std::string& vocalistName) const;
    void recordAcousticInstrument(const std::string& instrumentName) const;
    bool reduceBackgroundNoise() const;
    void increaseSensitivity(const double& maxSensitivity);
    
    JUCE_LEAK_DETECTOR(Microphone)
};
