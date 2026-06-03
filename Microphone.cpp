#include "Microphone.h"

Microphone::Microphone():
    microphoneType("Condenser"),
    sensitivityLevel(7),
    cableLenghtInMeters(5)
{
    std::cout << "Microphone being constructed!" << std::endl;
}

Microphone::~Microphone()
{
    std::cout << "Microphone being destructed!" << std::endl;
}

void Microphone::captureVocalRecording(const std::string& vocalistName) const
{
    std::cout << "Capturing vocals for " << vocalistName << "\n";
    std::cout << "Micropphone Type" << microphoneType << "\n";
    std::cout << "Cable Lenght In Meters " << cableLenghtInMeters << "\n";
}

void Microphone::recordAcousticInstrument(const std::string& instrumentName) const
{
    std::cout << "Recording acoustic instrument " << instrumentName << "\n";
}

bool Microphone::reduceBackgroundNoise() const
{
    std::cout << "Reducing background noise\n";

    return true;
}

void Microphone::increaseSensitivity(const double& maxSensitivity)
{
    while (sensitivityLevel < maxSensitivity)
    {
        sensitivityLevel += 0.5;
        std::cout << "Current sensitivity level: " << sensitivityLevel << '\n';

        if (sensitivityLevel >= maxSensitivity)
        {
            std::cout << "Maximum sensitivity reached!\n";
            return;
        }
    }
}
