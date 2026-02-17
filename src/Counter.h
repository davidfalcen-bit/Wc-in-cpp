#include "Filecounter.h"
#include "Options.h"
#include <cstddef>
#include <string_view>

class Counter 
{
public:
  Counter(const Options& opts);
  FileCounts process(const std::string &file_name);
private:
    Options opts;
};