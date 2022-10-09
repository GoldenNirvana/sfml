cmake_minimum_required(VERSION 3.16)
project(sfml)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")

add_executable(sfml main.cpp Button.cpp Button.hpp Scroll.cpp Scroll.hpp Game.cpp Game.hpp GameState.cpp GameState.hpp)

set(SFML_ROOT ../SFML)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics audio window system)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
endif()

