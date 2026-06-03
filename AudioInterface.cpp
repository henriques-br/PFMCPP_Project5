#include "AudioInterface.h"

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

void AudioInterface::convertAnalogToDigitalAudio() const
{
    std::cout << "Converting analog audio to digital audio\n";
}

void AudioInterface::sendAudioToStudioMonitors(const float& outputVolume)
{
    headphoneOutputVolume = outputVolume;

    std::cout << "Sending audio to studio monitors at volume " << outputVolume << "\n";
}

bool AudioInterface::connectMicrophone(const std::string& microphoneName) const
{
    std::cout << "Connecting microphone " << microphoneName << "\n";
    std::cout << "Number of Input Channels " << numOfInputChannels << "\n";
    std::cout << "Number of Output Channels " << numOfOutputChannels << "\n";

    return true;
}

void AudioInterface::increaseHeadphoneVolume(const float& volumeIncreaseAmount, const float& maximumSafeVolume)
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
