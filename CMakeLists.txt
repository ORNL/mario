cmake_minimum_required(VERSION 2.8)

project(MARIO)
include(GNUInstallDirs)

set(MARIO_VERSION_MAJOR 1)
set(MARIO_VERSION_MINOR 0)
set(MARIO_VERSION_PATCH 0)

set(MARIO_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(MARIO_INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(MARIO_BIN_DIR ${PROJECT_BINARY_DIR}/src)

ENABLE_TESTING()
include(CTest)

set(CTEST_PROJECT_NAME "mario")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

set(CTEST_DROP_METHOD "https")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=mario")
set(CTEST_DROP_SITE_CDASH TRUE)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)

