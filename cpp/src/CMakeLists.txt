add_library(substitution substitution.cpp substitution.h)
add_library(transposition transposition.cpp transposition.h)

add_library(primes primes.cpp primes.h)

# dynamic linking
target_link_libraries(primes PUBLIC PkgConfig::GMP)

# static linking
#target_include_directories(primes PUBLIC /usr/local/include)
#target_link_directories(primes PUBLIC /usr/local/lib)
#target_link_libraries(primes PRIVATE -l:libgmp.a -l:libgmpxx.a)

add_executable(ggcrypt ggcrypt.cpp)
target_link_libraries(ggcrypt PRIVATE substitution transposition primes)
target_link_libraries(ggcrypt PRIVATE CLI11::CLI11)
