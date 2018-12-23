set(SOURCES test_matrix.cpp matrix.cpp matrix.h)

add_executable(matrix ${SOURCES})
set_property(TARGET matrix PROPERTY CXX_STANDARD 14)