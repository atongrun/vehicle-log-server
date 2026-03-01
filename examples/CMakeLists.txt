add_executable(cpp_sdk_demo
  cpp_sdk_demo.cpp
)

target_link_libraries(cpp_sdk_demo
  PRIVATE
    vls_sdk_cpp
)
