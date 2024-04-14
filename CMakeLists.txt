cmake_minimum_required(VERSION 3.16)
project(PuzzleGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch dependencies
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(box2d
    GIT_REPOSITORY https://github.com/erincatto/Box2D.git
    GIT_TAG v2.3.1
)

set(BOX2D_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(box2d)

# CMakeLists of sub directories
add_subdirectory(source)
add_subdirectory(tests)
