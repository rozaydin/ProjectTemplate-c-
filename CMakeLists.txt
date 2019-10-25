cmake_minimum_required(VERSION 3.12)

project(sample_project
        VERSION 1.0.0
        DESCRIPTION "Sample Project"
        LANGUAGES CXX)

# Src
add_subdirectory(src)

# Test
add_subdirectory(test)

# Resource
add_subdirectory(resource)