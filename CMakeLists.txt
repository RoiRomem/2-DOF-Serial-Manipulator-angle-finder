cmake_minimum_required(VERSION 3.20)

project(2DOF C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB ENGINE_SOURCES "${PROJECT_SOURCE_DIR}/engine/*.c")

add_library(ik_engine SHARED ${ENGINE_SOURCES})
target_include_directories(ik_engine PUBLIC "${PROJECT_SOURCE_DIR}/engine")
target_link_libraries(ik_engine PUBLIC m)

add_executable(2DOF_app src/main.c)
target_link_libraries(2DOF_app PRIVATE ik_engine)
