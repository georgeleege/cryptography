add_executable(tests libcaesar_test.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(tests PRIVATE libcaesar Catch2::Catch2WithMain)
