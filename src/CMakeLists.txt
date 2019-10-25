include_directories(${PROJECT_SOURCE_DIR}/include/)

set(application
        "sample_project"
        )

set(Sources
        main.cpp
        )

set(Headers
        ${PROJECT_SOURCE_DIR}/include/sample_project/Banner.h
        ${PROJECT_SOURCE_DIR}/include/sample_project/Version.h
        )

# Change runtime output directory
# message("Before Output Directory is: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
# set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.67.0 COMPONENTS log log_setup system thread REQUIRED)

message("${Boost_LIBRARIES}")
message("boost is found: ${Boost_FOUND}")

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    set (CMAKE_CXX_FLAGS "-DBOOST_LOG_DYN_LINK")

    add_executable(${application} ${Sources} ${Headers})
    target_link_libraries (${application} PUBLIC ${Boost_LIBRARIES} -pthread)

    # add_executable(progname file1.cxx file2.cxx)
    # target_link_libraries(progname ${Boost_LIBRARIES})
endif()


set_target_properties( ${application}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

message("Binary Dir is: ${CMAKE_BINARY_DIR}")
message("Output Directory is: ${RUNTIME_OUTPUT_DIRECTORY}")

