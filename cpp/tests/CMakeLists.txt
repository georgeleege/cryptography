add_executable(tests
                caesar_test.cpp
                vigenere_test.cpp
                autokey_test.cpp
)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE
                      substitution
)
