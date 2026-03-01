add_library(vls_sdk_cpp
  src/logger.cpp
)

target_include_directories(vls_sdk_cpp
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(vls_sdk_cpp
  PUBLIC
    vls_core
)
