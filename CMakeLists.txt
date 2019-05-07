cmake_minimum_required(VERSION 3.0)
project(ets2-telemetry-server VERSION 3.2.5)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(ets2-sdk-plugin)
add_subdirectory(html)
add_subdirectory(server)
add_subdirectory(ui)
