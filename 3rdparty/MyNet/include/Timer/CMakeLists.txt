aux_source_directory(. DIR_TIMER_SRCS)
link_libraries(LOGGER)
link_libraries(THREADPOOL)
link_libraries(BUFFER)
link_libraries(MYSOCKET)
add_library(TIMER ${DIR_TIMER_SRCS})

include_directories(.)