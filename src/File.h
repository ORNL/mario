#ifndef MARIO_SRC_FILE_H
#define MARIO_SRC_FILE_H

#include "Config.h"
#include "Releasable.h"
#include <limits.h>
#include <regex.h>
#include <sys/types.h>

namespace mario {

class File {
public:
  File(char* path);
  ~File();

  int SetAttribute(int attribute, int value);
  int Print();

  int attribute(int attr);

  char* path() { return path_; }
  off_t size() const { return size_; }
  time_t ctime() const { return ctime_; }
  int step() const { return step_; }
  int level() const { return level_; }
  int rank() const { return rank_; }

private:
  char path_[PATH_MAX];
  off_t size_;
  time_t ctime_;
  int step_;
  int level_;
  int rank_;

};

} /* namespace mario */

#endif /* MARIO_SRC_FILE_H */
