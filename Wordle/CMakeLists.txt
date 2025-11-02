cmake_minimum_required(VERSION 3.10)

project(Wordle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(WordPad
    main.cpp
    MainWindow.cpp
    Document.cpp
    View.cpp
    Application.cpp
    Settings.cpp
    FileNewDialog.cpp
    DateTimeDialog.cpp
)

target_link_libraries(WordPad PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
