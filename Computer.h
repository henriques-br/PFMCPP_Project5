#pragma once
#include "LeakedObjectDetector.h"

/*
 copied UDT 3:
 */
struct Computer
{
    double cpuSpeedInGhz;
    int amountRamInGb;
    int storageSizeInGb = 8000;
    std::string operatingSystemName;
    int numOfUsbPorts = 8;

    Computer();
    ~Computer();
       
    void runAudioSoftware(const std::string& softwareName) const;
    void saveProjectFile(const std::string& projectName) const;
    int processAudioPlugins(const int& numOfPlugins) const;
    void allocateRamToPlugins(const int& ramIncreaseAmount) const;
    void printComputerInfo() const;
    
    JUCE_LEAK_DETECTOR(Computer)
};
