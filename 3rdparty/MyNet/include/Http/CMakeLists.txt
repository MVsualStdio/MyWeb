aux_source_directory(. DIR_HTTP_SRCS)
link_libraries(LOGGER)
link_libraries(THREADPOOL)
link_libraries(BUFFER)
link_libraries(MYSOCKET)
add_library(HTTP ${DIR_HTTP_SRCS})

include_directories(.)