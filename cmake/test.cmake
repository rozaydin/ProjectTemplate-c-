include_directories(extern/catch2)

add_executable(${TEST_EXE_NAME}
test/main.cpp
test/applicationTest.cpp
)

target_link_libraries(${TEST_EXE_NAME} 
${LIB_NAME}
gcov
)