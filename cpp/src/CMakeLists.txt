add_library(libcaesar libcaesar.cpp libcaesar.h)
add_library(libvigenere libvigenere.cpp libvigenere.h)

add_executable(caesar caesar.cpp)
target_link_libraries(caesar PRIVATE libcaesar)
