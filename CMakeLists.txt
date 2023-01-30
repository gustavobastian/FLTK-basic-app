cmake_minimum_required(VERSION 3.15)

project(practica-templates)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include_directories("${PROJECT_SOURCE_DIR}/include" "${PROJECT_BUILD_DIR}/include" "/lib/gtest/googletest/include/gtest" "${PROJECT_BUILD_DIR}/lib/gtest/googletest/include")



conan_basic_setup(NO_OUTPUT_DIRS)
add_subdirectory( src/dbService )
add_subdirectory( src/main )
add_subdirectory( src/windows )
add_subdirectory( test/ )
add_subdirectory( lib/gtest )


add_executable(practica src/main/main.cpp)


target_include_directories(practica PUBLIC ${FLTK_INCLUDE_DIRS} /include /lib/gtest/googletest/include/gtest)


# Use the global target
target_link_libraries(practica LINK_PUBLIC ${CONAN_LIBS} gtest gtest_main windowsLib db2Lib  fltk fltk_images Xft  sqlite3)


# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" OFF)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
