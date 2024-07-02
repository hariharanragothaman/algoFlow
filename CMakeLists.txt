cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(algoflow)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion")


# Find all *.cpp files in the project directory and its subdirectories
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)

# Loop through each source file and create an executable
foreach(SOURCE_FILE ${SOURCES})
    # Get the file name without the extension
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)
    # Create the executable
    add_executable(${TARGET_NAME} ${SOURCE_FILE})
    # Set the output directory for the executable
    set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
endforeach()
