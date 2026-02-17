cmake_minimum_required(VERSION 3.20)

project(wc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(wc
    main.cpp
    src/Counter.cpp
    src/Options.cpp
    src/Filecounter.cpp
)

target_include_directories(wc PRIVATE src)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(wc PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
    )
endif()
