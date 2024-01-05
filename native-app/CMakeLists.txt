set(NATIVE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../src)
file(GLOB native_srcs RELATIVE "${NATIVE_SRC_DIR}" "${NATIVE_SRC_DIR}/*.c")
foreach(srcfile IN LISTS native_srcs)
    # Get file name without directory
    get_filename_component(elfname ${srcfile} NAME_WE)
    add_executable(${elfname} ${NATIVE_SRC_DIR}/${srcfile})
    target_link_libraries(${elfname})
endforeach()