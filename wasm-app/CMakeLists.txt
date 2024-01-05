set(WASM_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(WASI_SDK_DIR "/opt/wasi-sdk")
set(CMAKE_C_COMPILER "${WASI_SDK_DIR}/bin/clang")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib -Wl,--no-entry -Wl,--allow-undefined")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -z stack-size=409600")
set (CMAKE_C_FLAGS                  "${CMAKE_C_FLAGS} -Wl,--export=malloc")
set (CMAKE_C_FLAGS                  "${CMAKE_C_FLAGS} -Wl,--export=free")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -nostdlib -Wl,--no-entry -Wl,--allow-undefined")

file(GLOB wasm-srcs RELATIVE "${WASM_SRC_DIR}" "${WASM_SRC_DIR}/*.c")
foreach(srcfile IN LISTS wasm-srcs)
    # Get file name without directory
    get_filename_component(elfname ${srcfile} NAME_WE)
    add_executable(${elfname}.wasm ${WASM_SRC_DIR}/${srcfile})
    target_link_libraries(${elfname}.wasm)
endforeach()