#include "Filecounter.h"
#include "Options.h"
#include <cstddef>
#include <string_view>

class Counter 
{
public:
  Counter() = default;
  FileCounts process(const std::string &file_name);
private:
    Options opts;
};