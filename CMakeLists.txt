cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME GameCpp)

project(${PROJECT_NAME})

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

find_package(PkgConfig)
find_package(SDL2 REQUIRED)

pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)

target_include_directories(${PROJECT_NAME} PRIVATE)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
