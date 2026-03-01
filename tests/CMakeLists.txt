add_executable(test_core_smoke
  test_core_smoke.c
)

target_link_libraries(test_core_smoke
  PRIVATE
    vls_core
)

add_test(NAME core_smoke COMMAND test_core_smoke)
