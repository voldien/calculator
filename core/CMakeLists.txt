

FILE(GLOB SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
FILE(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

#TODO relocate to the core.
# Core library for adding support for plugin.
ADD_LIBRARY(solver-core ${SOURCE_FILES} ${HEADER_FILES} include/scope.h include/ast.h include/error.h include/core-def.h include/hashTable.h src/hashTable.c)
TARGET_LINK_LIBRARIES(solver-core m)
TARGET_INCLUDE_DIRECTORIES(solver-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
SET_TARGET_PROPERTIES(solver-core PROPERTIES LANGUAGE C)
INSTALL(TARGETS solver-core DESTINATION lib)
