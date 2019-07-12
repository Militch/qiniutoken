cmake_minimum_required(VERSION 3.1)
project(qiniucli)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(PROJECT_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

find_path(GFLAGS_INCLUDE_DIR gflags/gflags.h)

find_library(GFLAGS_LIBRARY NAMES gflags)
find_library(CRYPTO_LIBRARY crypto)
find_library(CURL_LIBRARY curl)

include_directories(
    ${GFLAGS_INCLUDE_DIR}
    ./include
)

link_directories(./lib)

add_subdirectory(src)