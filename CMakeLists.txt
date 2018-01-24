project(mariadbcpp)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-O3 -Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align -Wunused -Wcast-qual -Woverloaded-virtual -Wconversion -Wsign-conversion -Wformat-security -Wwrite-strings -fdiagnostics-show-option")

add_library(${PROJECT_NAME} SHARED src/mariadbcpp.cpp src/bindcpp.cpp src/rescpp.cpp src/stmtcpp.cpp src/sqlexceptioncpp.cpp src/drivercpp.cpp src/connectioncpp.cpp)

