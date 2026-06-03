#include "StudioMonitors.h"

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

void StudioMonitors::playAudioPlayback(const std::string& audioFileName) const
{
    std::cout << "Playing audio file " << audioFileName << "\n";
}

void StudioMonitors::reproduceLowFrequencies() const
{
    std::cout << "Reproducing low frequencies\n";
}

void StudioMonitors::monitorRecordingSession(const int& sessionDurationInMinutes) const
{
    std::cout << "Monitoring recording session for " << sessionDurationInMinutes << " minutes\n";
    std::cout << "Power Outputs In Watts " << powerOutputsInWatts << "\n";
    std::cout << "Frequency Response Range In Hz" << frequencyResponseRangeInHz << "\n";
}

void StudioMonitors::increaseVolume(const float& volumeIncreaseAmount, const float& maximumSafeVolume)
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
