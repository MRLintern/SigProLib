cmake_minimum_required(VERSION 4.0.2)

project(Correlation VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")
set(CMAKE_CXX_EXTENSIONS OFF)

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INPUT_DIR "${PROJECT_SOURCE_DIR}/Input_Signals")

file(GLOB SOURCES "${SRC_DIR}/*.cpp")

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE ${INCLUDE_DIR})

file(GLOB DATA_FILES "${INPUT_DIR}/*.dat")
file(COPY ${DATA_FILES} DESTINATION ${PROJECT_BINARY_DIR})