#include "MixingStudio.h"

MixingStudio::MixingStudio()
{
    std::cout << "MixingStudio being constructed!" << std::endl;
    computer.allocateRamToPlugins(8);
    midiKeyboard.playNotes(3);
    studioMonitors.increaseVolume(2.f, 50.f);
}

MixingStudio::~MixingStudio()
{
    std::cout << "MixingStudio being destructed!" << std::endl;
    studioMonitors.playAudioPlayback("Final Mix Bounce.wav");
}

void MixingStudio::mixSong(const std::string& songName) const
{
    computer.processAudioPlugins(25);

    midiKeyboard.controlVirtualInstrument("Synth Pad");

    studioMonitors.playAudioPlayback(songName);

    std::cout << "Mixing song: " << songName << '\n';
}

void MixingStudio::processMixSessions(const int& numOfSessions)
{
    for (int sessionNum = 1; sessionNum <= numOfSessions; ++sessionNum)
    {
        ++numOfMixesCompleted;

        std::cout << "Processing mix session #" << sessionNum << '\n';

        for (int plugin = 1; plugin <= 3; ++plugin)
        {
            std::cout << "Loading plugin #" << plugin << '\n';
        }

        if (numOfMixesCompleted >= 5)
        {
            std::cout << "Daily mixing limit reached\n";
            return;
        }
    }
}

void MixingStudio::printMixingStudioInfo() const
{
    std::cout << "Mixing Engineer: " << this->mixingEngineerName << '\n';
    std::cout << "Mixes Completed: " << this->numOfMixesCompleted << '\n';
    std::cout << "CPU Usage Percentage: " << this->sessionCpuUsagePercentage << '\n';
    std::cout << "Computer RAM: " << this->computer.amountRamInGb << '\n';
    std::cout << "Monitor Volume: " << this->studioMonitors.volumeLevel << '\n';
}
