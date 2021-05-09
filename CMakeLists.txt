cmake_minimum_required(VERSION 3.8)
project(dtest-demo)
set(CXX_FLAGS
        -g
        # -DVALGRIND
        -DCHECK_PTHREAD_RETURN_VALUE
        -D_FILE_OFFSET_BITS=64
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -Wno-unused-parameter
        -Wold-style-cast
        -Woverloaded-virtual
        -Wpointer-arith
        -Wshadow
        -Wwrite-strings
        -march=native
        # -MMD
        -rdynamic
        )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(. "./third_part/include")
link_directories(. "./third_part/lib")

aux_source_directory(. src_files)

add_executable(dtestDemo ${src_files})

target_link_libraries(dtestDemo smncpp dtest actions pthread )
add_subdirectory(actions)

