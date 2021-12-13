#ifndef MARIO_SRC_REPOSITORY_H
#define MARIO_SRC_REPOSITORY_H

#include "Config.h"
#include "Releasable.h"
#include <limits.h>
#include <map>
#include <regex.h>
#include <vector>

namespace mario {

class File;

class Repository : public Releasable<struct _mario_repository, Repository> {
public:
  Repository(const char* path);
  ~Repository();

  int Build(const char* pattern, int nmatches, int* matches);
  int Analyze1D(int group, std::map<int, off_t>* m1);
  int Print1D(int group, FILE* stream);
  int Print2D(int group1, int group2, FILE* stream);
  int Print3D(int group1, int group2, int group3, FILE* stream);
  int Formula(int group, int* formulas, int nformulas, FILE* stream);

  char* path() { return path_; }

private:
  int BuildDir(char* path);
  int AddFile(char* filename);

private:
  char path_[PATH_MAX];
  char pattern_[1024];
  int nmatches_;
  int matches_[3];
  regex_t regex_;
  std::vector<File*> files_;
};

} /* namespace mario */

#endif /* MARIO_SRC_REPOSITORY_H */
