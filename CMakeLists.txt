project(mariadbcpp)
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-O2 -Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Wcast-qual -Woverloaded-virtual -Wconversion -Wsign-conversion -Wlogical-op -Wformat-security -Wwrite-strings -fdiagnostics-show-option")

add_library(${PROJECT_NAME} STATIC src/mariadb.cpp)

