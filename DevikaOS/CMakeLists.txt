cmake_minimum_required(VERSION 3.27)
project(DevikaOS C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(src/include)

add_executable(DevikaOS
        src/kernel.c
        src/string.c
        src/system.c
        src/screen.c
        src/idt.c
        src/isr.c
        src/keyboard.c
        src/shell.c
        src/shell.c
        src/util.c
        src/util.c
)
