#include "Computer.h"

Computer::Computer():
    cpuSpeedInGhz(4),
    amountRamInGb(128),
    operatingSystemName("MacOS Tahoe")
{
    std::cout << "Computer being constructed!" << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer being destructed!" << std::endl;
}

void Computer::runAudioSoftware(const std::string& softwareName) const
{
    std::cout << "Running audio software " << softwareName << "\n";
    std::cout << "Operating System Name " << operatingSystemName << "\n";
}

void Computer::saveProjectFile(const std::string& projectName) const
{
    std::cout << "Saving project file " << projectName << "\n";
}

int Computer::processAudioPlugins(const int& numOfPlugins) const
{
    std::cout << "Processing " << numOfPlugins << " audio plugins\n";

    return numOfPlugins;
}

void Computer::allocateRamToPlugins(const int& ramIncreaseAmount) const
{
    for(int i = 0; i <= ramIncreaseAmount; i++)
    {
        std::cout << "Allocating RAM To Plugins " << i << "\n";
        if(i >= 16)
        {
            std::cout << "Maximum amount reached " << i << "\n";
            return;
        }
    }
    
    std::cout << "Maximum RAM capacity reached.\n";
}

void Computer::printComputerInfo() const
{
    std::cout << "CPU Speed: " << this->cpuSpeedInGhz << '\n';
    std::cout << "RAM Amount: " << this->amountRamInGb << '\n';
    std::cout << "Operating System: " << this->operatingSystemName << '\n';
}
