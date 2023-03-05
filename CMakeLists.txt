cmake_minimum_required(VERSION 3.7.2)
project(networkd VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(CURL REQUIRED)

add_compile_options(-Wall -Wextra -Wconversion -pedantic -Wformat-security -Wfatal-errors)

include_directories(include)

set(SOURCES
    src/networkStats.cpp
    src/Network.cpp
    main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})

target_include_directories(networkd PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(networkd PRIVATE ${CURL_LIBRARIES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})