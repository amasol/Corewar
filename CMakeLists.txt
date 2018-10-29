cmake_minimum_required(VERSION 3.12)
project(corewar C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIBA)

add_executable(corewar
        ${LIBA}
        corewar.h
        main.c)

link_libraries(libft/libftprintf.a)