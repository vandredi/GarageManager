cmake_minimum_required(VERSION 3.25)
project(GarageManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(GarageManager
        main.cpp
        src/Car.cpp
        src/Moto.cpp
        src/Bus.cpp
        src/Keeper.cpp
        src/Exceptions.cpp
        src/Vehicle.cpp
)