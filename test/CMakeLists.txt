cmake_minimum_required(VERSION 3.5)

project(
  test
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/ListWidgets
    ${CMAKE_SOURCE_DIR}/res
)

set(HEADERS mainwindow.h
    ListWidgets/deviceinfo.h
    ListWidgets/IListObject.h
    ListWidgets/TabButton.h
    ListWidgets/listobjectwrapper.h
    ListWidgets/customdialog.h
)

set(SOURCES
    main.cpp
    mainwindow.cpp
    ListWidgets/deviceinfo.cpp
    ListWidgets/TabButton.cc
    ListWidgets/listobjectwrapper.cc
    ListWidgets/customdialog.cc
)

set(UI
    mainwindow.ui
    ListWidgets/deviceinfo.ui
    ListWidgets/listobjectwrapper.ui
    ListWidgets/customdialog.ui
)

set(RESOURCES
    res/res.qrc
)

set(PROJECT_SOURCES
    ${SOURCES}
    ${HEADERS}
    ${UI}
    ${RESOURCES}
)

if(WIN32)
    set(INSTALL_EXAMPLEDIR "./")

    find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

    qt_add_executable(test
        ${PROJECT_SOURCES}
    )

    set_target_properties(test PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
    )

    target_link_libraries(test PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
    )

    install(TARGETS test
        RUNTIME DESTINATION "${INSTALL_DIR}"
        BUNDLE DESTINATION "${INSTALL_DIR}"
        LIBRARY DESTINATION "${INSTALL_DIR}"
    )

else()
    set(CMAKE_AUTORCC ON)

    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

    if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
      qt_add_executable(test MANUAL_FINALIZATION ${PROJECT_SOURCES})
    else()
      if(ANDROID)
        add_library(test SHARED ${PROJECT_SOURCES})
      else()
        add_executable(test ${PROJECT_SOURCES})
      endif()
    endif()

    target_link_libraries(test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

    set_target_properties(
      test
      PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
                 MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
                 MACOSX_BUNDLE_SHORT_VERSION_STRING
                 ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
                 MACOSX_BUNDLE TRUE
                 WIN32_EXECUTABLE TRUE)

    if(QT_VERSION_MAJOR EQUAL 6)
      qt_finalize_executable(test)
    endif()
endif()
