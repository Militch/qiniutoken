aux_source_directory(. DIR_SRCS)
aux_source_directory(./util DIR_SRCS_UTIL)

add_executable(qiniutoken ${DIR_SRCS})

TARGET_LINK_LIBRARIES(qiniutoken qiniu curl ssl crypto z gflags)

install(TARGETS qiniutoken DESTINATION ${PROJECT_INSTALL_BIN_DIR})
