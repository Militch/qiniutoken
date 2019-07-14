aux_source_directory(. DIR_SRCS)
aux_source_directory(./util DIR_SRCS_UTIL)

add_executable(qiniutoken ${DIR_SRCS})

if(CMAKE_SYSTEM MATCHES "^Linux")
    TARGET_LINK_LIBRARIES(qiniutoken qiniu curl ssl crypto z gflags)
elseif(CMAKE_SYSTEM MATCHES "^Darwin")
    TARGET_LINK_LIBRARIES(qiniutoken qiniu ${CURL_LIBRARY} ${CRYPTO_LIBRARY} gflags)
else()
    message(FATAL_ERROR "This platform is not supported")
endif()

install(TARGETS qiniutoken DESTINATION ${PROJECT_INSTALL_BIN_DIR})
