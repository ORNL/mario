#include <mario/mario.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  char* path = argc > 1 ? argv[1] : ".";

  int match[3] = { mario_step, mario_level, mario_rank };
  int formulas[5] = { mario_linear, mario_datagrowth, mario_quadratic, mario_cubic, mario_log };

  mario_repository repo;
  mario_repository_create(path, &repo);
  mario_repository_build(repo, "plt([0-9]*)/Level_([0-9]*)/Cell_D_([0-9]*)", 3, match);
  mario_repository_print1D(repo, mario_step, stdout);
  mario_repository_formula(repo, mario_step, formulas, 5, stdout);

  return 0;
}

