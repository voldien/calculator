LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )
INCLUDE(cxxopt)

# Main executable.
ADD_EXECUTABLE(solver main.cpp)
TARGET_LINK_LIBRARIES(solver solver-core solver-math cxxopts)
INSTALL(TARGETS solver DESTINATION bin)