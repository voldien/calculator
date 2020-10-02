


# Main executable.
ADD_EXECUTABLE(solver main.c opt.c lexer-set.c lexer-set.h parser-set.h parset-set.c opt.h semantic-analysis.c solver.c)
TARGET_LINK_LIBRARIES(solver solver-core)
INSTALL(TARGETS solver DESTINATION bin)