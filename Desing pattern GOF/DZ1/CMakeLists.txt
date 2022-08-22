cmake_minimum_required(VERSION 3.23)

project(GB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GB main.cpp src/SBomber.cpp src/Bomb.cpp src/Crater.cpp src/Ground.cpp
    src/House.cpp src/LevelGUI.cpp src/MyTools.cpp src/Plane.cpp src/ScreenSingleton.cpp src/Tank.cpp)
target_include_directories( GB PUBLIC include include/enums src)
