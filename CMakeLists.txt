cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
project(v2.0)

# Include directories
include_directories(include)

# Add your source files
file(GLOB SOURCES "src/*.cpp")

# Create an executable
add_executable(pirma_uzd ${SOURCES})

