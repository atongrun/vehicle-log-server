cmake_minimum_required(VERSION 3.20)
project(vehicle_log_server VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(VLS_BUILD_EXAMPLES "Build examples" ON)
option(VLS_BUILD_TESTS "Build tests" ON)

if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

enable_testing()

add_subdirectory(core)
add_subdirectory(sdk)

if(VLS_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if(VLS_BUILD_TESTS)
  add_subdirectory(tests)
endif()
