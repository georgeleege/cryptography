add_library(substitution substitution.cpp substitution.h)
add_library(transposition transposition.cpp transposition.h)

add_executable(ggcrypt ggcrypt.cpp)
target_link_libraries(ggcrypt PRIVATE substitution)
target_link_libraries(ggcrypt PRIVATE CLI11::CLI11)
