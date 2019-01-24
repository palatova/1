cmake_minimum_required(VERSION 3.6)



project(cursach LANGUAGES CXX)



set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Sql)

set(project_ui
    tablica_zakazov1.ui
    costume.ui
    mainwindow.ui
    nalichie.ui
    zakaz1.ui)

set(project_headers
    costume.h
    mainwindow.h
    tablica_zakazov1.h
    zakaz1.h)

set(project_sources
    costume.cpp
    main.cpp
    mainwindow.cpp
    nalichie.cpp
    tablica_zakazov1.cpp
    vozvrat.cpp
    zakaz1.cpp)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources} 
    ${project_sources_moc} ${project_headers_wrapped})

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Sql
)