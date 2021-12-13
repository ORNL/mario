include_directories(${MARIO_INC_DIR})
include_directories(00_common)

macro(mario_test arg)
    add_executable(${arg} ${arg}.c)
    target_link_libraries(${arg} mario pthread)
    add_test(${arg} ./${arg})
    #    set_tests_properties(${arg} PROPERTIES FAIL_REGULAR_EXPRESSION "MARIO_ERR")
endmacro(mario_test)

add_subdirectory(01_repository_print)
add_subdirectory(02_repository_formula)
