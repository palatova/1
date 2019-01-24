set(SOURCES test_stack_on_array.cpp stack_on_array.cpp stack_on_array.h)

add_executable(stack_on_array ${SOURCES})
set_property(TARGET stack_on_array PROPERTY CXX_STANDARD 14)