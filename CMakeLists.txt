cmake_minimum_required(VERSION 3.20)
project(wasi-test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_subdirectory(native-app)
add_subdirectory(wasm-app)