set(SOURCES test_queueonarray.cpp queueonarray.cpp queueonarray.h)

add_executable(queueonarray ${SOURCES})
set_property(TARGET queueonarray PROPERTY CXX_STANDARD 14)