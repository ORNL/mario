#include <mario/mario.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char* path = argc > 1 ? argv[1] : ".";
  int group1 = argc > 2 ? atoi(argv[2]) : mario_step;
  int group2 = argc > 3 ? atoi(argv[3]) : -1;
  int group3 = argc > 4 ? atoi(argv[4]) : -1;

#if 1
  int match[3] = { mario_step, mario_level, mario_rank };

  mario_repository repo;
  mario_repository_create(path, &repo);
  mario_repository_build(repo, "plt([0-9]*)/Level_([0-9]*)/Cell_D_([0-9]*)", 3, match);
  mario_repository_print3D(repo, group1, group2, group3, stdout);
#else
  int match[2] = { mario_rank, mario_step };

  mario_repository repo;
  mario_repository_create(path, &repo);
  mario_repository_build(repo, "_([0-9]*)_([0-9]*).json", 2, match);
  mario_repository_print2D(repo, group1, group2, stdout);
#endif

  return 0;
}

