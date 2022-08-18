cmake_minimum_required(VERSION 3.23)

project(GB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GB main.cpp Bomb.h Bomb.cpp Crater.h Crater.cpp DestroyableGroundObject.h
    DynamicObject.h GameObject.h Ground.h Ground.cpp House.h House.cpp
    LevelGUI.h LevelGUI.cpp MyTools.h MyTools.cpp Plane.h Plane.cpp SBomber.h SBomber.cpp
    ScreenSingleton.h ScreenSingleton.cpp Tank.h Tank.cpp ConsoleColors.h CraterSize.h)
