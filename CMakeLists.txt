cmake_minimum_required(VERSION 2.8)
project(platformer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SFML COMPONENTS graphics window system)

include_directories(
    include/
    ${SFML_INCLUDE_DIRS}
)

set(SOURCES
    src/gamestatemanager.cpp

    src/main.cpp
)

set(LIBRARIES
    ${SFML_LIBRARIES}
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})