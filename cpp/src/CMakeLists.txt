add_library(substitution substitution.cpp substitution.h)
add_library(transposition transposition.cpp transposition.h)

add_executable(caesar caesar.cpp)
target_link_libraries(caesar PRIVATE substitution)
target_link_libraries(caesar PRIVATE CLI11::CLI11)
