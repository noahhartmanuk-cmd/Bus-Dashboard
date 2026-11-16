cmake_minimum_required(VERSION 3.16)
project(BusDashboard C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(lvgl)

add_executable(bus-dashboard 
    main.c
    cJSON/cJSON.c
)

target_include_directories(bus-dashboard PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/cJSON
)

target_compile_options(bus-dashboard PRIVATE -Wall -Wpedantic -Wextra -Werror)

find_package(SDL2 REQUIRED)
target_link_libraries(bus-dashboard PRIVATE lvgl SDL2::SDL2 )