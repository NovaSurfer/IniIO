cmake_minimum_required(VERSION 3.9.2)

project(IniIO)

set(CMAKE_CXX_STANDARD 17)

#file(MAKE_DIRECTORY  ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
configure_file(${CMAKE_SOURCE_DIR}/tests/mocks/testIni_01.ini ${CMAKE_BINARY_DIR} COPYONLY)

set(SOURCE_FILES src/ini_io.h src/ini_io.cpp tests/ini_io_test.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(IniIO ${SOURCE_FILES})

target_link_libraries(IniIO gtest gtest_main)
target_link_libraries(IniIO ${GTEST_BOTH_LIBRARIES})
target_link_libraries(IniIO ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
gtest_add_tests(IniIO "" AUTO)