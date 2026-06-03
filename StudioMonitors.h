#pragma once
#include "LeakedObjectDetector.h"

struct StudioMonitors
{
    double speakerSizeInInches;
    int powerOutputsInWatts;
    float frequencyResponseRangeInHz;
    float volumeLevel = 45.f;
    double cabinetWidthInCm = 30;

    StudioMonitors();
    ~StudioMonitors();
    
    void playAudioPlayback(const std::string& audioFileName) const;
    void reproduceLowFrequencies() const;
    void monitorRecordingSession(const int& sessionDurationInMinutes) const;
    void increaseVolume(const float& volumeIncreaseAmount, const float& maximumSafeVolume);
    
    JUCE_LEAK_DETECTOR(StudioMonitors)
};
