# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-src"
  "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-build"
  "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest"
  "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-tmp"
  "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-stamp"
  "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-src"
  "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/donghaosen/donghaosen/ops2023/aitisa_api/third_party/gtest/gtest-stamp${cfgdir}") # cfgdir has leading slash
endif()
