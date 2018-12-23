set(SOURCES test_queueonlist.cpp queueonlist.cpp queueonlist.h)

add_executable(queueonlist ${SOURCES})
set_property(TARGET queueonlist PROPERTY CXX_STANDARD 14)