#include "RecordingSession.h"

RecordingSession::RecordingSession():
    sessionDurationInMinutes(120)
{
    std::cout << "RecordingSession being constructed!" << std::endl;
    
    computer.runAudioSoftware("Pro Tools");
    audioInterface.connectMicrophone("Shure SM7B");
    microphone.reduceBackgroundNoise();
}

RecordingSession::~RecordingSession()
{
    std::cout << "RecordingSession being destructed!" << std::endl;
    computer.saveProjectFile(sessionName);
    std::cout << "Final track count: " << numOfTracksRecorded << '\n';
}

void RecordingSession::startSession(const std::string& vocalistName) const
{
    computer.runAudioSoftware("Logic Pro");

    audioInterface.convertAnalogToDigitalAudio();

    microphone.captureVocalRecording(vocalistName);

    std::cout << "Starting recording session: " << sessionName << "\n";
}

void RecordingSession::recordTracks(const int& numOfTracks)
{
    for (int trackNum = 1; trackNum <= numOfTracks; ++trackNum)
    {
        ++numOfTracksRecorded;

        std::cout << "Recording track #" << trackNum << '\n';

        if (numOfTracksRecorded >= 10)
        {
            std::cout << "Maximum number of tracks recorded\n";
            return;
        }
    }
}

void RecordingSession::printRecordingSessionInfo() const
{
    std::cout << "Session Name: " << this->sessionName << '\n';
    std::cout << "Session Duration: " << this->sessionDurationInMinutes << '\n';
    std::cout << "Tracks Recorded: " << this->numOfTracksRecorded << '\n';
    std::cout << "Computer Operating System: " << this->computer.operatingSystemName << '\n';
    std::cout << "Microphone Type: " << this->microphone.microphoneType << '\n';
}
