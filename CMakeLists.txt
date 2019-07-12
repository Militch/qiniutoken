cmake_minimum_required(VERSION 3.1)

project(qiniutoken)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(PROJECT_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

find_path(GFLAGS_INCLUDE_DIR gflags/gflags.h)

find_library(GFLAGS_LIBRARY NAMES gflags)
find_library(CRYPTO_LIBRARY crypto)
find_library(CURL_LIBRARY curl)

include_directories(
    ${GFLAGS_INCLUDE_DIR}
    include
)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

if(CMAKE_SYSTEM_NAME MATCHES "^Linux.+amd64$")
    link_directories(lib/linux/amd64)
elseif(CMAKE_SYSTEM_NAME MATCHES "^Darwin")
    link_directories(lib/darwin)
else()
    message(FATAL_ERROR "This platform is not supported")
endif()

add_subdirectory(src)