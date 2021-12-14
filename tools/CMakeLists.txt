include_directories(${MARIO_INC_DIR})

set(MARIO_CASTRO_SOURCES mario_castro.c)

add_executable(mario-castro mario_castro.c)
add_executable(mario-castro-weights mario_castro_weights.c)
target_link_libraries(mario-castro mario)
target_link_libraries(mario-castro-weights mario)

install(TARGETS mario-castro mario-castro-weights DESTINATION ${CMAKE_INSTALL_BINDIR})

