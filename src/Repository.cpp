#include "Repository.h"
#include "Debug.h"
#include "File.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <map>

namespace mario {

Repository::Repository(const char* path) {
  _info("path[%s]", path);
  strcpy(path_, path);
}

Repository::~Repository() {
}

int Repository::SetPattern(const char* pattern, int nmatches, int* matches) {
  memset(pattern_, 0, sizeof(pattern_));
  strcpy(pattern_, pattern);
  nmatches_ = nmatches;
  for (int i = 0; i < nmatches; i++) matches_[i] = matches[i];
  if (regcomp(&regex_, pattern, REG_EXTENDED) != 0) {
    _error("pattern[%s]", pattern);
    return MARIO_ERR;
  }
  return MARIO_SUCCESS;
}

int Repository::Build() {
  return BuildDir(path_);
}

int Repository::BuildDir(char* path) {
  DIR* dp = opendir(path);
  if (dp == NULL) {
    _error("path[%s]", path);
    return MARIO_ERR;
  }
  for (struct dirent* ep = readdir(dp); ep != NULL; ep = readdir(dp)) {
    if (strcmp(".", ep->d_name) == 0 || strcmp("..", ep->d_name) == 0) continue;
    char filename[PATH_MAX];
    memset(filename, 0, PATH_MAX);
    sprintf(filename, "%s/%s", path, ep->d_name);
    if (ep->d_type == DT_DIR) BuildDir(filename);
    else AddFile(filename);
  }
  closedir(dp);
  return MARIO_SUCCESS;
}

int Repository::AddFile(char* filename) {
  regmatch_t match[4];
  if (regexec(&regex_, filename, nmatches_ + 1, match, 0) != 0) return MARIO_SUCCESS;
  File* file = new File(filename);
  for (int i = 1; i < nmatches_ + 1; i++) {
    char str[16];
    memset(str, 0, sizeof(str));
    strncpy(str, filename + match[i].rm_so, match[i].rm_eo - match[i].rm_so);
    file->SetAttribute(matches_[i - 1], atoi(str));
  }
  files_.push_back(file);
  return MARIO_SUCCESS;
}

int Repository::Print(int group, FILE* stream) {
  if (group == mario_step || group == mario_level || group == mario_rank)
    return Print1D(group, stream);
  _error("not implemented for group[%x]", group);
  return MARIO_ERR;
}

int Repository::Print1D(int group, FILE* stream) {
  fprintf(stream, "== %s ==\n", path_);
  std::map<int, off_t> db;  
  for (auto I = files_.begin(), E = files_.end(); I != E; ++I) {
    File* file = *I;
    int key = file->attribute(group);
    off_t size = file->size();
    if (db.count(key) == 0) db.insert(std::pair<int, off_t>(key, size));
    else {
      off_t s = db[key];
      db[key] = s + size;
    }
  }
  for (auto I = db.begin(), E = db.end(); I != E; ++I) {
    fprintf(stream, "%s [%05d]: FileSize [%10lu]\n",
        group == mario_step ? "Step" : group == mario_level ? "Level" : "Rank",
        I->first, I->second);
  }

  return MARIO_ERR;
}

} /* namespace mario */
