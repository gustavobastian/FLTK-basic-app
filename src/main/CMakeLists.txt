file( GLOB system_SOURCES *.cpp )
add_library( practicaLib ${system_SOURCES} )
target_include_directories(practicaLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
