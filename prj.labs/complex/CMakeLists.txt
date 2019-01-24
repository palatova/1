set(SOURCES test_complex.cpp complex.cpp complex.h)

add_executable(complex ${SOURCES})
set_property(TARGET complex PROPERTY CXX_STANDARD 14)