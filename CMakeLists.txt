cmake_minimum_required(VERSION 3.10)
project(minishell C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

include_directories(
    incs
    libs/libmylist
    libs/libmystr
    libs/libft
    /opt/homebrew/opt/readline/include
)

file(GLOB_RECURSE SRCS
    "srcs/builtins/cd/*.c"
    "srcs/builtins/echo/*.c"
    "srcs/builtins/env/*.c"
    "srcs/builtins/export/*.c"
    "srcs/builtins/exit/*.c"
    "srcs/builtins/unset/*.c"
    "srcs/builtins/pwd/*.c"
    "srcs/presh/*.c"
    "srcs/clear/*.c"
    "srcs/expand_utils/*.c"
    "srcs/wildcard/*.c"
    "srcs/utils/*.c"
    "srcs/executor/*.c"
    "srcs/lexer/*.c"
    "srcs/parser/*.c"
    "srcs/tokenizer/*.c"
    "mnsh.c"
)

add_custom_target(libmylist_build
    COMMAND ${CMAKE_MAKE_PROGRAM} -C ${CMAKE_SOURCE_DIR}/libs/libmylist
)

add_custom_target(libmystr_build
    COMMAND ${CMAKE_MAKE_PROGRAM} -C ${CMAKE_SOURCE_DIR}/libs/libmystr
)

add_custom_target(libft_build
    COMMAND ${CMAKE_MAKE_PROGRAM} -C ${CMAKE_SOURCE_DIR}/libs/libft
)

add_library(libmylist STATIC IMPORTED)
set_target_properties(libmylist PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libmylist/libmylist.a)

add_library(libmystr STATIC IMPORTED)
set_target_properties(libmystr PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libmystr/libmystr.a)

add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libft/libft.a)

if(UNIX AND NOT APPLE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
endif()

link_directories(/opt/homebrew/opt/readline/lib)

add_executable(${PROJECT_NAME} ${SRCS})
add_dependencies(${PROJECT_NAME} libmylist_build libmystr_build libft_build)
target_link_libraries(${PROJECT_NAME} libmylist libmystr libft readline)