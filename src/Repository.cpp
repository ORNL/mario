#include "Repository.h"
#include "Debug.h"
#include "File.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>

namespace mario {

Repository::Repository(const char* path) {
  strcpy(path_, path);
}

Repository::~Repository() {
}

int Repository::Build(const char* pattern, int nmatches, int* matches) {
  memset(pattern_, 0, sizeof(pattern_));
  strcpy(pattern_, pattern);
  nmatches_ = nmatches;
  for (int i = 0; i < nmatches; i++) matches_[i] = matches[i];
  if (regcomp(&regex_, pattern, REG_EXTENDED) != 0) {
    _error("pattern[%s]", pattern);
    return MARIO_ERR;
  }
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

int Repository::Analyze1D(int group, std::map<int, off_t>* m1) {
  for (auto I = files_.begin(), E = files_.end(); I != E; ++I) {
    File* file = *I;
    int key = file->attribute(group);
    off_t size = file->size();
    if (m1->count(key) == 0) m1->insert(std::pair<int, off_t>(key, size));
    else {
      off_t s = m1->at(key);
      (*m1)[key] = s + size;
    }
  }
  return MARIO_SUCCESS;
}

int Repository::Print1D(int group, FILE* stream) {
  fprintf(stream, "== %s ==\n", path_);
  std::map<int, off_t> m1;  
  Analyze1D(group, &m1);
  for (auto I = m1.begin(), E = m1.end(); I != E; ++I) {
    fprintf(stream, "%s [%5d]: FileSize [%10lu]\n",
        group == mario_step ? "Step" : group == mario_level ? "Levl" : "Rank",
        I->first, I->second);
  }
  return MARIO_SUCCESS;
}

int Repository::Print2D(int group1, int group2, FILE* stream) {
  if (group2 < 0) return Print1D(group1, stream);
  fprintf(stream, "== %s ==\n", path_);
  std::map<int, std::map<int, off_t>*> m1;  
  std::map<int, off_t>* m2;
  for (auto I = files_.begin(), E = files_.end(); I != E; ++I) {
    File* file = *I;
    int key1 = file->attribute(group1);
    int key2 = file->attribute(group2);
    off_t size = file->size();
    if (m1.count(key1) == 0) {
      m2 = new std::map<int, off_t>;
      m1[key1] = m2;
    } else m2 = m1[key1];
    if (m2->count(key2) == 0) m2->insert(std::pair<int, off_t>(key2, size));
    else {
      off_t s = (*m2)[key2];
      (*m2)[key2] = s + size;
    }
  }

  for (auto I = m1.begin(), E = m1.end(); I != E; ++I) {
    int key1 = I->first;
    std::map<int, off_t>* m2 = I->second;
    fprintf(stream, "%s  [%5d]\n" RESET,
        group1 == mario_step ? "Step" : group1 == mario_level ? "Levl" : "Rank", key1);
    for (auto I2 = m2->begin(), E2 = m2->end(); I2 != E2; ++I2) {
      fprintf(stream, " %s [%5d]: FileSize [%10lu]\n",
          group2 == mario_step ? "Step" : group2 == mario_level ? "Levl" : "Rank",
          I2->first, I2->second);
    }
  }
  return MARIO_SUCCESS;
}

int Repository::Print3D(int group1, int group2, int group3, FILE* stream) {
  if (group3 < 0) return Print2D(group1, group2, stream);
  fprintf(stream, "== %s ==\n", path_);
  std::map<int, std::map<int, std::map<int, off_t>*>*> m1;  
  std::map<int, std::map<int, off_t>*>* m2;
  std::map<int, off_t>* m3;

  for (auto I = files_.begin(), E = files_.end(); I != E; ++I) {
    File* file = *I;
    int key1 = file->attribute(group1);
    int key2 = file->attribute(group2);
    int key3 = file->attribute(group3);
    off_t size = file->size();
    if (m1.count(key1) == 0) {
      m2 = new std::map<int, std::map<int, off_t>*>;
      m1[key1] = m2;
    } else m2 = m1[key1];
    if (m2->count(key2) == 0) {
      m3 = new std::map<int, off_t>;
      (*m2)[key2] = m3;
    } else m3 = (*m2)[key2];
    if (m3->count(key3) == 0) m3->insert(std::pair<int, off_t>(key3, size));
    else {
      off_t s = (*m3)[key3];
      (*m3)[key3] = s + size;
    }
  }

  for (auto I = m1.begin(), E = m1.end(); I != E; ++I) {
    int key1 = I->first;
    std::map<int, std::map<int, off_t>*>* m2 = I->second;
    fprintf(stream, "%s   [%5d]\n",
        group1 == mario_step ? "Step" : group1 == mario_level ? "Levl" : "Rank", key1);
    for (auto I2 = m2->begin(), E2 = m2->end(); I2 != E2; ++I2) {
      int key2 = I2->first;
      std::map<int, off_t>* m3 = I2->second;
      fprintf(stream, " %s  [%5d]\n",
          group2 == mario_step ? "Step" : group2 == mario_level ? "Levl" : "Rank", key2);
      for (auto I3 = m3->begin(), E3 = m3->end(); I3 != E3; ++I3) {
        fprintf(stream, "  %s [%5d]: FileSize [%10lu]\n",
            group3 == mario_step ? "Step" : group3 == mario_level ? "Levl" : "Rank",
            I3->first, I3->second);
      }
    }
  }
  return MARIO_SUCCESS;
}

int Repository::Formula(int group, int* formulas, int nformulas, FILE* stream) {
  std::map<int, off_t> m1;  
  Analyze1D(group, &m1);
  double val0 = 0;
  double val1 = 0;
  int nsteps = -1;
  int step_diff = 0;
  int step_last = 0;
  for (auto I = m1.begin(), E = m1.end(); I != E; ++I) {
    int step = I->first;
    off_t filesize = I->second;
    if (nsteps > 0 && (step - step_last) != step_diff) break;
    if (step_diff == 0 && I != m1.begin()) step_diff = step;
    if (I == m1.begin()) val0 = (double) filesize;
    val1 = (double) filesize;
    step_last = step;
    nsteps++;
  }
  _debug("nsteps[%d] step_diff[%d] val0[%lu] val1[%lu]", nsteps, step_diff, val0, val1);

  double linear = (val1 - val0) / nsteps;
  double datagrowth = pow(val1 / val0, 1 / (double) nsteps);
  double quadratic = (val1 - val0) / (step_diff * nsteps * step_diff * nsteps);
  double cubic = (val1 - val0) / (step_diff * nsteps * step_diff * nsteps * step_diff * nsteps);
  double loga = (val1 - val0) / log10(step_diff * nsteps);

  _debug("linear[%lf] datagrowth[%lf] quadratic[%lf] cubic[%lf] log[%lf]", linear, datagrowth, quadratic, cubic, loga);

  return MARIO_SUCCESS;
}

} /* namespace mario */
