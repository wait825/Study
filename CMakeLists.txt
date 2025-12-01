cmake_minimum_required(VERSION 3.25)

project(test)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ./source/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
