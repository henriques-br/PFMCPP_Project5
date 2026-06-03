#include "MidiKeyboard.h"

MidiKeyboard::MidiKeyboard():
    isVelocitySensitivityEnabled(true),
    usbConnectionType("USB-C")
{
    std::cout << "MidiKeyboard being constructed!" << std::endl;
}

MidiKeyboard::~MidiKeyboard()
{
    std::cout << "MidiKeyboard being destructed!" << std::endl;
}

void MidiKeyboard::sendMidiNotes(const int& midiNoteNumber) const
{
    std::cout << "Sending MIDI note " << midiNoteNumber << "\n";
}

void MidiKeyboard::controlVirtualInstrument(const std::string& instrumentName) const
{
    std::cout << "Controlling virtual instrument " << instrumentName << "\n";
    std::cout << "USB Connection Type " << usbConnectionType << "\n";
    std::cout << "Velocity Sensitivity Enabled " << (isVelocitySensitivityEnabled == 1 ? "TRUE" : "FALSE") << "\n";
}

void MidiKeyboard::adjustPluginParameter(const std::string& parameterName, const float& parameterValue) const
{
    std::cout << "Adjusting parameter " << parameterName << " to " << parameterValue << "\n";
}

void MidiKeyboard::playNotes(const int& numOfNotes) const
{
    std::cout << "\nPlaying MIDI notes...\n";

    for (int note = 1; note <= numOfNotes; ++note)
    {
        std::cout << "Playing note #" << note << '\n';

        if (note >= 5)
        {
            std::cout << "Stopping playback early.\n";
            return;
        }
    }
}
