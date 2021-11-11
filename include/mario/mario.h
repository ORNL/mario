#ifndef MARIO_INCLUDE_MARIO_MARIO_H
#define MARIO_INCLUDE_MARIO_MARIO_H

#include <stdio.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MARIO_SUCCESS               0
#define MARIO_ERR                   8

#define mario_step                  (1 << 0)
#define mario_level                 (1 << 1)
#define mario_rank                  (1 << 2)

typedef struct _mario_repository*   mario_repository;

extern int mario_repository_create(const char* path, mario_repository* repo);
extern int mario_repository_build(mario_repository repo, const char* pattern, int nmatches, int* matches);
extern int mario_repository_print1D(mario_repository repo, int group, FILE* stream);
extern int mario_repository_print2D(mario_repository repo, int group1, int group2, FILE* stream);
extern int mario_repository_print3D(mario_repository repo, int group1, int group2, int group3, FILE* stream);

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif /* MARIO_INCLUDE_MARIO_MARIO_H */

