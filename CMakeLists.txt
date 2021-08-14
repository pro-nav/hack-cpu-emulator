# CMakeList.txt : CMake project for hack-cpu-emulator

cmake_minimum_required (VERSION 3.8)

project ("hack-cpu-emulator")

set(SOURCES
    src/main.cpp
    src/CPU.cpp
    src/MEM_RAM.cpp
    src/MEM_ROM.cpp
)

add_executable (hack-cpu-emulator ${SOURCES})

target_include_directories(hack-cpu-emulator
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
