cmake_minimum_required(VERSION 3.7...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
      cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(Cryptography VERSION 1.0
                     DESCRIPTION "Cryptography"
                     LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/Catch2)
