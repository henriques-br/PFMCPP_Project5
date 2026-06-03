#pragma once
#include "Computer.h"
#include "AudioInterface.h"
#include "Microphone.h"
#include "LeakedObjectDetector.h"

/*
 new UDT 4:
 with 2 member functions
 */
struct RecordingSession
{
    Computer computer;
    AudioInterface audioInterface;
    Microphone microphone;

    int sessionDurationInMinutes;
    int numOfTracksRecorded = 0;
    std::string sessionName = "Rock Session";

    RecordingSession();
    ~RecordingSession();

    void startSession(const std::string& vocalistName) const;
    void recordTracks(const int& numOfTracks);
    void printRecordingSessionInfo() const;
    
    JUCE_LEAK_DETECTOR(RecordingSession)
};
