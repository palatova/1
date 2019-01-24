set(SOURCES test_stack_on_list.cpp stack_on_list.cpp stack_on_list.h)

add_executable(stack_on_list ${SOURCES})
set_property(TARGET stack_on_list PROPERTY CXX_STANDARD 14)