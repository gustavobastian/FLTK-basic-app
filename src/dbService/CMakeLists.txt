file( GLOB system_SOURCES *.cpp )


add_library( dbLib ${system_SOURCES})
target_include_directories(dbLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

file( GLOB system_SOURCES *.cpp )

add_library( db2Lib ${system_SOURCES} )
target_include_directories(db2Lib PUBLIC sqlite3 ${CMAKE_CURRENT_SOURCE_DIR} )

