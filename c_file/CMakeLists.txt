cmake_minimum_required(VERSION 3.15)
project(c_file C)

set(CMAKE_C_STANDARD 99)

add_executable(c_file main.c file_operate.c file_operate.h)