cmake_minimum_required(VERSION 3.9.2)

project(IniIO)

set(CMAKE_CXX_STANDARD 17)

file(MAKE_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(IniIO src/ini_io.h src/ini_io.cpp tests/ini_io_test.cpp)

configure_file(${CMAKE_SOURCE_DIR}/testdata/testIni_01.ini ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)

target_link_libraries(IniIO ${GTEST_BOTH_LIBRARIES})
target_link_libraries(IniIO ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
GTEST_ADD_TESTS(IniIO "" tests/ini_io_test.cpp)