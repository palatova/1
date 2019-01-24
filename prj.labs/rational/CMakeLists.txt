set(SOURCES test_rational.cpp rational.cpp rational.h)

add_executable(rational ${SOURCES})
set_property(TARGET rational PROPERTY CXX_STANDARD 14)