file( GLOB system_SOURCES *.cpp )
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_library( testLib ${system_SOURCES} )
include_directories("${PROJECT_SOURCE_DIR} /include /lib/gtest/googletest/include/gtest/")
target_include_directories(testLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}  "/lib/gtest/googletest/include/gtest/")

add_executable(test_runner test_runner.cpp )
add_executable(mock_runner mock_runner.cpp )
target_link_libraries(test_runner  LINK_PUBLIC  ${CONAN_LIBS} gtest gtest_main windowsLib db2Lib  fltk fltk_images Xft  sqlite3)
target_link_libraries(mock_runner  LINK_PUBLIC  ${CONAN_LIBS} gtest gtest_main windowsLib db2Lib  fltk fltk_images Xft  sqlite3)