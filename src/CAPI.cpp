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

int mario_repository_pattern(mario_repository srepo, const char* pattern, int nmatches, int* matches) {
  Repository* repo = srepo->class_obj;
  return repo->SetPattern(pattern, nmatches, matches);
}

int mario_repository_build(mario_repository srepo) {
  Repository* repo = srepo->class_obj;
  return repo->Build();
}

int mario_repository_print(mario_repository srepo, int group, FILE* stream) {
  Repository* repo = srepo->class_obj;
  return repo->Print(group, stream);
}

