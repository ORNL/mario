#include "File.h"
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

namespace mario {

File::File(char* path) {
  memset(path_, 0, sizeof(path_));
  strncpy(path_, path, strlen(path));
  struct stat buf;
  stat(path, &buf);
  size_ = buf.st_size;
  ctime_ = buf.st_ctime;
}

File::~File() {

}

int File::SetAttribute(int attribute, int value) {
  switch(attribute) {
    case mario_step:  step_ = value;  break;
    case mario_level: level_ = value; break;
    case mario_rank:  rank_ = value;  break;
    default: _error("attribute[%d]", attribute); return MARIO_ERR;
  }
  return MARIO_SUCCESS;
}

int File::attribute(int attr) {
  if (attr == mario_step) return step_;
  if (attr == mario_level) return level_;
  if (attr == mario_rank) return rank_;
  _error("attr[%x]", attr);
  return -1;
}

int File::Print() {
  struct tm *tmp = gmtime(&ctime_);
  _info("path[%s] step[%d] level[%d] rank[%d] size[%lu] time[%02d/%02d/%d %02d:%02d:%02d]", path_, step_, level_, rank_, size_, tmp->tm_mon, tmp->tm_mday, 1900 + tmp->tm_year, tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
  return MARIO_SUCCESS;
}

} /* namespace mario */

