#pragma once
#include "LeakedObjectDetector.h"

struct AudioInterface
{
    int numOfInputChannels;
    int numOfOutputChannels;
    double sampleRateInKhz;
    bool isPhantomPowerEnabled = true;
    float headphoneOutputVolume = 45.5f;

    AudioInterface();
    ~AudioInterface();
       
    void convertAnalogToDigitalAudio() const;
    void sendAudioToStudioMonitors(const float& outputVolume);
    bool connectMicrophone(const std::string& microphoneName) const;
    void increaseHeadphoneVolume(const float& volumeIncreaseAmount, const float& maximumSafeVolume);
    
    JUCE_LEAK_DETECTOR(AudioInterface)
};
