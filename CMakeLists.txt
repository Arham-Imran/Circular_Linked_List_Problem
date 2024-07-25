cmake_minimum_required(VERSION 3.5.0)
project(Circular_Linked_List_Problem VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(./include)
add_executable(Circular_Linked_List_Problem main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_link_libraries(${PROJECT_NAME} PUBLIC timing)
add_compile_options("-Wall")
