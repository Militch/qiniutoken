cmake_minimum_required(VERSION 3.1)

project(qiniutoken)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(PROJECT_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

find_library(CRYPTO_LIBRARY crypto)
find_library(CURL_LIBRARY curl)

message(STATUS "gflags lib: ${GFLAGS_LIBRARY}")
message(STATUS "crypto lib: ${CRYPTO_LIBRARY}")
message(STATUS "CURL lib: ${CURL_LIBRARY}")


include_directories(
    include
)

if(CMAKE_SYSTEM MATCHES "^Linux.+64$") 
    link_directories(
        lib/linux/amd64 
        lib/linux/amd64/qiniu_openssl11
    )
elseif(CMAKE_SYSTEM MATCHES "^Darwin")
    link_directories(lib/darwin)
else()
    message(FATAL_ERROR "This platform is not supported")
endif()

add_subdirectory(src)
