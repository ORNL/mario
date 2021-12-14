option(BUILD_SHARED_LIBS "Build shared libs" ON)

include_directories(${MARIO_INC_DIR})
include_directories(${MARIO_BIN_DIR})

configure_file(Config.h.in Config.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")
if (CMAKE_VERSION VERSION_LESS "3.1")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
  set(CMAKE_CXX_STANDARD 17)
endif()

set(MARIO_RUNTIME_SOURCES
  CAPI.cpp
  File.cpp
  Releasable.cpp
  Repository.cpp
  )

add_library(mario ${MARIO_RUNTIME_SOURCES})

install(TARGETS mario DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_subdirectory(tools)
