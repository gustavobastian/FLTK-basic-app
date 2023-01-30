file( GLOB system_SOURCES *.cpp )
find_package(SQLite3 REQUIRED)
include_directories("${PROJECT_SOURCE_DIR} /include")

add_library( windowsLib ${system_SOURCES} )
target_include_directories(windowsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} /include)

