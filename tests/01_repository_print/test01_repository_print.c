#include <mario/mario.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char* path = argc > 1 ? argv[1] : ".";
  int group = argc > 2 ? atoi(argv[2]) : mario_step;

  mario_repository repo;
  int match[3] = { mario_step, mario_level, mario_rank };

  mario_repository_create(path, &repo);
  mario_repository_pattern(repo, "plt([0-9]*)/Level_([0-9]*)/Cell_D_([0-9]*)", 3, match);
  mario_repository_build(repo);
  mario_repository_print(repo, group, stdout);

  return 0;
}

