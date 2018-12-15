cmake_minimum_required(VERSION 3.12)
project(corewar C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIBA)

add_executable(corewar
        ${LIBA}
        include/corewar.h
        libft/libft.h
        include/op.h
        src/main.c
        src/error.c
        src/shift_bit.c
        src/save_bot.c
        src/function_check.c
        src/op.c
        src/ft_sti.c
        src/ft_and.c)

link_libraries(libft/libftprintf.a)