#vmake minimum version required
cmake_minimum_required(VERSION 3.10)

# project name

project(ToDoList)
# c++ version
set(CMAKE_CXX_STANDARD 11)

# add source files
set(SOURCES
        main.cpp
        todo.cpp
)

add_executable(ToDoList ${SOURCES})