cmake_minimum_required(VERSION 3.14)
project(TroubleBall)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# This is the main part:
set(SOURCES IObject.h
            ButtonObject/button.cc
            BoulderObject/boulder.cc

            IScreen.h
            StartScreen/start_screen.cc
            GameScreen/game_screen.cc
            
            Animator/animator.cc
            
            main.cc
            )
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

# Add include directories for your components
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/ButtonObject
    ${CMAKE_CURRENT_SOURCE_DIR}/BoulderObject
    ${CMAKE_CURRENT_SOURCE_DIR}/Event
    ${CMAKE_CURRENT_SOURCE_DIR}/EventDispatcher
    ${CMAKE_CURRENT_SOURCE_DIR}/StartScreen
    ${CMAKE_CURRENT_SOURCE_DIR}/GameScreen
    ${CMAKE_CURRENT_SOURCE_DIR}/Animator
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")

    # Required linker flags for using Raylib with Emscripten
    target_link_options(${PROJECT_NAME} PRIVATE -sEXPORTED_FUNCTIONS=['_main','_malloc'] -sEXPORTED_RUNTIME_METHODS=ccall -sUSE_GLFW=3)
endif()

# That's it! You should have an example executable that you can run. Have fun!
