include_directories(${MARIO_INC_DIR})

set(MARIO_CASTRO_SOURCES mario_castro.c)

add_executable(mario-castro ${MARIO_CASTRO_SOURCES})
target_link_libraries(mario-castro mario)

install(TARGETS mario-castro DESTINATION ${CMAKE_INSTALL_BINDIR})

