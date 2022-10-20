aux_source_directory(. DIR_SOCKET_SRCS)
link_libraries(LOGGER)
link_libraries(THREADPOOL)
link_libraries(BUFFER)
add_library(MYSOCKET ${DIR_SOCKET_SRCS})

include_directories(.)