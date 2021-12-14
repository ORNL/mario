#include <mario/mario.h>
#include "Debug.h"
#include "Repository.h"

namespace mario {
  const char* mario_log_prefix_= "MARIO";
}

using namespace mario;

int mario_repository_create(const char* path, mario_repository* srepo) {
  Repository* repo = new Repository(path);
  *srepo = repo->struct_obj();
  return MARIO_SUCCESS;
}

int mario_repository_build(mario_repository srepo, const char* pattern, int nmatches, int* matches) {
  Repository* repo = srepo->class_obj;
  return repo->Build(pattern, nmatches, matches);
}

int mario_repository_print1D(mario_repository srepo, int group, FILE* stream) {
  Repository* repo = srepo->class_obj;
  return repo->Print1D(group, stream);
}

int mario_repository_print2D(mario_repository srepo, int group1, int group2, FILE* stream) {
  Repository* repo = srepo->class_obj;
  return repo->Print2D(group1, group2, stream);
}

int mario_repository_print3D(mario_repository srepo, int group1, int group2, int group3, FILE* stream) {
  Repository* repo = srepo->class_obj;
  return repo->Print3D(group1, group2, group3, stream);
}

int mario_repository_formula(mario_repository srepo, int group, FILE* stream) {
  Repository* repo = srepo->class_obj;
  return repo->Formula(group, stream);
}

