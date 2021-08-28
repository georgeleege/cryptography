add_library(substitution substitution.cpp substitution.h)

add_executable(caesar caesar.cpp)
target_link_libraries(caesar PRIVATE substitution)
