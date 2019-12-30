cmake_minimum_required(VERSION 3.15)

# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extern/CMake-codecov/cmake" ${CMAKE_MODULE_PATH})
# set(CMAKE_CXX_COMPILER /usr/bin/x86_64-linux-gnu-g++-9)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC" ) # -fpic --coverage
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project( SomeProject
         VERSION 1.0.0
         DESCRIPTION "Code Coverage Sample Project!"
         LANGUAGES CXX
)

# CLANG Tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Release MinSizeRel
set(CMAKE_BUILD_TYPE Debug)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

set(EXE_NAME
${PROJECT_NAME}
) 

set(LIB_NAME
${PROJECT_NAME}_lib
)

set(TEST_EXE_NAME
${PROJECT_NAME}_test
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(include_directories)
include(local)
include(test)

if(CMAKE_COMPILER_IS_GNUCXX)    
    include(CodeCoverage)  
    append_coverage_compiler_flags()  
    #set(COVERAGE_EXCLUDES
    #          'test/*'              
    #          'extern/*'              
    #          )
    #set(COVERAGE_LCOV_EXCLUDES 
    #"/usr/include/*" 
    #"/usr/include/c++/*"
    #"/usr/include/x86_64-linux-gnu/c++/7/bits/*"    
    #)
    # SETUP_TARGET_FOR_COVERAGE_LCOV(NAME coverage
    #                          EXECUTABLE ${TEST_EXE_NAME}
    #                          )
    setup_target_for_coverage_gcovr_xml(NAME coverage
                                        EXECUTABLE ${TEST_EXE_NAME}
                                        )
endif()

# clang tidy task
add_custom_target(clangtidy
# COMMAND clang-tidy -checks='*' -p ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/**/*.hpp > clang-tidy-report.txt
COMMAND clang-tidy -checks='*' -header-filter="^include" -p . ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/application/*.hpp > clang-tidy-report.txt
)

# 66e4e6072b0763410f7aaa09550dc174a03fd45f