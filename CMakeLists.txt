CMAKE_MINIMUM_REQUIRED(VERSION 3.7.2)
PROJECT(solver C CXX)

# Build shared/dynamic library option
OPTION(BUILD_SHARED_LIBS "Build package with shared libraries." ON)
OPTION(BUILD_WITH_COVERAGE "Enable profiling and coverage report analysis." ON)
OPTION(BUILD_WITH_PROFILER "Enable profiling." ON)
IF(NOT BUILD_SHARED_LIBS)
    SET(CMAKE_EXE_LINKER_FLAGS "-static")
    SET(LINK_SEARCH_START_STATIC TRUE)
ENDIF(NOT BUILD_SHARED_LIBS)

OPTION(BUILD_WITH_TEST "Enable Testing." ON)
OPTION(BUILD_WITH_DOCS "Build documentation." OFF)

# Set version of the project.
SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 6)
SET(VERSION_REVISION 0)
SET(VERSION_STATE a)
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}${VERSION_STATE}${VERSION_REVISION} )
SET(PROJECT_VERSION "${VERSION}")

# Set predefined macro for version.
ADD_DEFINITIONS(-DSOC_VERSION="${VERSION}")

# GCC compiler flag options.
IF((CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX) AND NOT CMAKE_COMPILER_IS_MINGW)
    IF (BUILD_SHARED_LIBS AND CMAKE_SIZEOF_VOID_P EQUAL 8) # -fPIC is only required
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    ENDIF()

    ADD_DEFINITIONS(-Wall -w)
    ADD_DEFINITIONS()
    IF (CMAKE_BUILD_TYPE STREQUAL "Release")
        MESSAGE(STATUS "Compile for release.")
        ADD_DEFINITIONS(-DNDEBUG)
        ADD_DEFINITIONS(-O2)
        SET(CMAKE_RELEASE TRUE)
        SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
    ELSE()
        MESSAGE(STATUS "Compile for debug.")
        ADD_DEFINITIONS(-D_DEBUG)
        ADD_DEFINITIONS(-g3 -O0)
        SET(CMAKE_DEBUG TRUE)
        ADD_DEFINITIONS(-D_GLIBCXX_ASSERTIONS)
    ENDIF()

    #
    IF(BUILD_WITH_COVERAGE)
        MESSAGE(STATUS "Building with coverage")
        SET(GCC_COVERAGE_COMPILE_FLAGS "--coverage -fprofile-arcs -ftest-coverage")
        SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")
        SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
        SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
    ENDIF()

    #
    IF(BUILD_WITH_PROFILER)
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
        SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
        SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
    ENDIF()

ENDIF()


FILE(GLOB SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
FILE(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

#TODO relocate to the core.
# Core library for adding support for plugin.
ADD_LIBRARY(solver-core ${SOURCE_FILES} ${HEADER_FILES} include/scope.h include/ast.h include/error.h include/core-def.h include/hashTable.h src/hashTable.c)
TARGET_LINK_LIBRARIES(solver-core m)
TARGET_INCLUDE_DIRECTORIES(solver-core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
SET_TARGET_PROPERTIES(solver-core PROPERTIES LANGUAGE C)
INSTALL(TARGETS solver-core DESTINATION lib)

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/test)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/console)


FIND_PACKAGE(Doxygen)
# Generate documentations.
IF(DOXYGEN_FOUND)
    MESSAGE(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE} -- ${DOXYGEN_VERSION}")
    IF(BUILD_WITH_DOCS)
        ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/docs/)
    ENDIF(BUILD_WITH_DOCS)
ENDIF()

# Only UNIX systems.
IF( UNIX )
    Find_PACKAGE(UnixCommands REQUIRED)

    # Create distribution tarball.
    SET( TARGETDIR "${PROJECT_NAME}-${VERSION}")
    ADD_CUSTOM_TARGET(	distribution
            COMMENT "Creating distrubtion file."
            COMMAND mkdir -p ${TARGETDIR}
            COMMAND ${CP} -r   ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
            client/fragview.1
            ${CMAKE_CURRENT_SOURCE_DIR}/.gitignore
            ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE
            ${TARGETDIR}
            COMMAND ${TAR} cf - ${TARGETDIR} | ${GZIP} -c > ${TARGETDIR}.tar.gz
            COMMAND ${RM} -r ${TARGETDIR} )
ENDIF()