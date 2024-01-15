cmake_minimum_required(VERSION 3.5)

project(MyMazeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files here
set(SOURCES
    main.cpp
    Maze.cpp
    Robot.cpp
    Node.cpp
)

# Add your header files here
set(HEADERS
    Maze.h
    Robot.h
    Node.h
)

add_executable(MyMazeProject ${SOURCES} ${HEADERS})

