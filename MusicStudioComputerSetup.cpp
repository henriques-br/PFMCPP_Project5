#include "MusicStudioComputerSetup.h"

MusicStudioComputerSetup::MusicStudioComputerSetup()
{
    std::cout << "MusicStudioComputerSetup being constructed!" << std::endl;
}

MusicStudioComputerSetup::~MusicStudioComputerSetup()
{
    std::cout << "MusicStudioComputerSetup being destructed!" << std::endl;
}

void MusicStudioComputerSetup::recordMusic(const std::string& projectName) const
{
    computer.runAudioSoftware(projectName);

    microphone.captureVocalRecording("Lead Vocalist");

    audioInterface.convertAnalogToDigitalAudio();

    std::cout << "Recording music project: " << projectName << "\n";
}

void MusicStudioComputerSetup::editAudioTrack(const std::string& trackName) const
{
    computer.saveProjectFile(trackName);

    studioMonitors.monitorRecordingSession(60);

    std::cout << "Editing audio track: " << trackName << "\n";
}

void MusicStudioComputerSetup::playVirtualInstrument(const std::string& instrumentName) const
{
    midiKeyboard.controlVirtualInstrument(instrumentName);

    studioMonitors.playAudioPlayback(instrumentName);

    std::cout << "Playing virtual instrument: " << instrumentName << "\n";
}

void MusicStudioComputerSetup::runRecordingSessions(const int& numOfSessions)
{
    std::cout << "\nRunning recording sessions...\n";

    for (int session = 1; session <= numOfSessions; ++session)
    {
        ++numOfProjectsCompleted;

        std::cout << "Completed recording session #" << session << " Projects completed: " << numOfProjectsCompleted << '\n';

        if (numOfProjectsCompleted >= 5)
        {
            std::cout << "Studio reached daily project limit.\n";
            return;
        }
    }
}
