aux_source_directory(. DIR_SRCS)
aux_source_directory(./util DIR_SRCS_UTIL)

add_executable(qiniucli ${DIR_SRCS})

target_link_libraries(
    qiniucli
    ${GFLAGS_LIBRARY}
    ${CRYPTO_LIBRARY}
    ${CURL_LIBRARY}
    qiniu
)
install(TARGETS qiniucli DESTINATION ${PROJECT_INSTALL_BIN_DIR})