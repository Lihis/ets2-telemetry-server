set(SERVER_SOURCES
    server/HttpServer.h
    server/HttpServer.cpp

    server/TelemeteryHelper.h
    server/TelemeteryHelper.cpp

    server/WebSocket.cpp
    server/WebSocket.h
    )

find_library(LIBEVENT2 event)
if (NOT LIBEVENT2)
    message(FATAL_ERROR "libevent not found.")
endif()
find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(websocketpp REQUIRED)

configure_file(server/Version.h.in Version.h)

add_library(libserver STATIC ${SERVER_SOURCES})

set_target_properties(libserver
                      PROPERTIES
                      OUTPUT_NAME "server"
                      PREFIX "lib"
                      )

target_include_directories(libserver
                           PUBLIC
                           "${CMAKE_CURRENT_SOURCE_DIR}"
                           "${CMAKE_CURRENT_BINARY_DIR}"
                           ${WEBSOCKETPP_INCLUDE_DIR}
                           )

target_link_libraries(libserver
                      PUBLIC
                      ${LIBEVENT2}
                      ${CMAKE_THREAD_LIBS_INIT}
                      ets2telemetry::plugindefs
                      )
