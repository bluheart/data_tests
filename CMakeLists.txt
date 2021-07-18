cmake_minimum_required(VERSION 3.0.0)
project(data_tests VERSION 0.1.0)

include(CTest)
enable_testing()


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(SOURCES main.c data/set.c)
add_executable(data_tests ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
