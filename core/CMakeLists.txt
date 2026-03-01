add_library(vls_core
  src/vls_core.c
  src/vls_config.c
)

target_include_directories(vls_core
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(UNIX AND NOT APPLE)
  target_link_libraries(vls_core PUBLIC pthread)
endif()

add_executable(vlsd
  src/main.c
)

target_link_libraries(vlsd PRIVATE vls_core)
