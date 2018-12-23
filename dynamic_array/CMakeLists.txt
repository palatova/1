set(SOURCES test_dynamic_array.cpp dynamic_array.cpp dynamic_array.h)

add_executable(dynamic_array ${SOURCES})
set_property(TARGET dynamic_array PROPERTY CXX_STANDARD 14)