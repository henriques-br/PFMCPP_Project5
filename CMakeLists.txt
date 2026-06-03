cmake_minimum_required(VERSION 3.10.2)
project(default VERSION 0.0.1)
add_executable(main
              main.cpp
              Wrappers.cpp
              CoffeeShop.cpp
              FitnessTracker.cpp
              Computer.cpp
              AudioInterface.cpp
              StudioMonitors.cpp
              MidiKeyboard.cpp
              Microphone.cpp
              MusicStudioComputerSetup.cpp
              RecordingSession.cpp
              MixingStudio.cpp)
              target_compile_features(main PUBLIC cxx_std_17)