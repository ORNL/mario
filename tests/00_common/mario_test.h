#ifndef MARIO_TESTS_00_COMMON_MARIO_TEST_H
#define MARIO_TESTS_00_COMMON_MARIO_TEST_H

#include <mario/mario.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MARIO_CALL(call) do {                                          \
  int err = call;                                                     \
  if (err != MARIO_SUCCESS) {                                          \
    printf("[%s:%d] MARIO_ERR[%d]\n", __FILE__, __LINE__, err);        \
    exit(EXIT_FAILURE);                                               \
  }                                                                   \
} while (0)

#define MARIO_PRINT(fmt, ...) do {                                     \
  printf("[%s:%d] " fmt "\n", __FILE__, __LINE__, __VA_ARGS__);       \
  } while (0)

#define MARIO_EQUAL_INT32(e, i) do {                                   \
  if (e != i) {                                                       \
    printf("[%s:%d] exp[%d] in[%d]\n", __FILE__, __LINE__, exp, in);  \
    exit(EXIT_FAILURE);                                               \
  }                                                                   \
} while (0)

#define MARIO_EQUAL_INT64(e, i) do {                                   \
  if (e != i) {                                                       \
    printf("[%s:%d] exp[%ld] in[%ld]\n", __FILE__, __LINE__, e, i);   \
    exit(EXIT_FAILURE);                                               \
  }                                                                   \
} while (0)

#define MARIO_EQUAL_STR(e, i) do {                                     \
  if (strcmp(e, i) != 0) {                                            \
    printf("[%s:%d] exp[%s] in[%s]\n", __FILE__, __LINE__, e, i);     \
    exit(EXIT_FAILURE);                                               \
  }                                                                   \
} while (0)

#endif /* MARIO_TESTS_00_COMMON_MARIO_TEST_H */

