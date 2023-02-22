# Distributed under the OSI-approved MIT License.  See accompanying
# file LICENSE or https://github.com/Crascit/DownloadProject for details.

cmake_minimum_required(VERSION 2.8.2)

project(gtest-download NONE)

include(ExternalProject)
ExternalProject_Add(gtest-download
                    GIT_REPOSITORY;https://github.com/google/googletest.git;GIT_TAG;v1.8.x;GIT_PROGRESS;TRUE;UPDATE_DISCONNECTED 1
                    PREFIX              "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest"
                    DOWNLOAD_DIR        "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-src"
                    SOURCE_DIR          "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-src"
                    BINARY_DIR          "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-build"
                    TMP_DIR             "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-tmp"
                    STAMP_DIR           "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-stamp"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
)
