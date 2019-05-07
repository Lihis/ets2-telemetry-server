set(BASE_SOURCES
    Base/AboutDialog.h
    Base/AboutDialog.cpp

    Base/Dialogs.h
    Base/Dialogs.cpp

    Base/MainWindow.h
    Base/MainWindow.cpp

    Base/SetupDialog.h
    Base/SetupDialog.cpp
    )

set(HELPERS_SOURCES
    Helpers/Game.h
    Helpers/Game.cpp

    Helpers/Network.h
    Helpers/Network.cpp

    Helpers/Plugin.h

    Helpers/Plugin.h
    Helpers/Plugin.cpp
    )

set(UI_SOURCES
    AboutDialog.h
    AboutDialog.cpp

    IApplication.h
    Application.h
    Application.cpp

    Dialog.h
    Dialog.cpp

    Config.h
    Config.cpp

    MainWindow.h
    MainWindow.cpp

    SetupDialog.h
    SetupDialog.cpp

    main.cpp
    )

find_package(wxWidgets 3.0 REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(ets2-telemetry-server ${BASE_SOURCES} ${HELPERS_SOURCES} ${UI_SOURCES})

if (MINGW)
    set(PLATFORM_LINK_LIBS -lwsock32 -lws2_32 -liphlpapi)
endif()

target_link_libraries(ets2-telemetry-server
                      PRIVATE
                      libserver
                      ${wxWidgets_LIBRARIES}
                      ${PLATFORM_LINK_LIBS}
                      )

target_include_directories(ets2-telemetry-server
                           PRIVATE
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           ${wxWidgets_INCLUDE_DIRS}
                           )

target_compile_options(ets2-telemetry-server
                       PRIVATE
                       ${wxWidgets_CFLAGS_OTHER}
                       )
