set(directory
    ${PROJECT_BINARY_DIR}/bin/resource)
# during configure time
file(MAKE_DIRECTORY ${directory})
configure_file(Banner.txt ${directory} COPYONLY)