cmake_minimum_required(VERSION 4.0.2)

project(SignalRMS VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

file(GLOB SOURCES "./src/*.cpp" "./hpp")

add_executable(main ${SOURCES})

# Copy input file to build directory after build
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/file1.dat
    ${CMAKE_SOURCE_DIR}/file2.dat
    $<TARGET_FILE_DIR:main>

)




    #$<TARGET_FILE_DIR:main>/input_signal.dat
    #$<TARGET_FILE_DIR:main>/InputSignal_f32_1kHz_15kHz.dat
#)