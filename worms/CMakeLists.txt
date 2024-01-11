cmake_minimum_required(VERSION 3.10.2)
project(worms)

set(CMAKE_CXX_STANDARD 17)
set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER ON) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF ON) # if you need SDL_ttf support

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_subdirectory(SDL2pp)
add_subdirectory(Box2D)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB_RECURSE COMMON_SRCS ./common_libs/src/*.cpp)
add_library(libcommon STATIC ${COMMON_SRCS})

include_directories(${CMAKE_SOURCE_DIR}/client/include)
include_directories(${CMAKE_SOURCE_DIR}/editor/include)

include_directories(${CMAKE_SOURCE_DIR}/server/include)
include_directories(${CMAKE_SOURCE_DIR}/common_libs/include)

target_link_libraries(libcommon SDL2pp Qt5::Widgets)
target_link_libraries(libcommon ${CMAKE_SOURCE_DIR}/Box2D/build/bin/libbox2d.a)

file(GLOB_RECURSE SERVER_SRCS ./server/src/*.cpp)
list(FILTER SERVER_SRCS EXCLUDE REGEX "main.cpp")

file(GLOB_RECURSE EDITOR_SRCS ./editor/src/*.cpp)
list(FILTER EDITOR_SRCS EXCLUDE REGEX "main.cpp")

add_library(libserver STATIC ${SERVER_SRCS})
target_link_libraries(libserver libcommon)

add_library(libeditor STATIC ${EDITOR_SRCS})
target_link_libraries(libeditor libcommon)

file(GLOB_RECURSE CLIENT_SRCS ./client/src/*.cpp)
list(FILTER CLIENT_SRCS EXCLUDE REGEX "main.cpp")

add_library(libclient STATIC ${CLIENT_SRCS})
target_link_libraries(libclient libcommon)

add_executable(worms-client "client/src/main.cpp")
target_link_libraries(worms-client libclient)

add_executable(worms-server "server/src/main.cpp")
target_link_libraries(worms-server libserver)

add_executable(worms-editor "editor/src/main.cpp")
target_link_libraries(worms-editor libeditor)

file(COPY ${CMAKE_SOURCE_DIR}/maps DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

install(TARGETS worms-server worms-client worms-editor libclient libserver libcommon libeditor
        ARCHIVE DESTINATION "lib"
        RUNTIME DESTINATION "bin"
        INCLUDES DESTINATION "include")
