cmake_minimum_required(VERSION 3.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)

string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})

set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES  get_next_line.c get_next_line_utils.c get_next_line.h main.c)

add_executable(${PROJECT_NAME} ${SOURCES} )