cmake_minimum_required(VERSION 3.24)
project(rk2)

set(CMAKE_CXX_STANDARD 17)

add_executable(rk2 main.cpp tasks_rk2.cpp tasks_rk2.h lsfilofifo.h)
