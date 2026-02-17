#pragma once
#include <cstddef>
#include <string>
#include <string_view>
#include "Options.h"
struct FileCounts
{
  std::size_t lines{};
  std::size_t words{};
  std::size_t characters{};
  std::size_t bytes{};
  std::size_t maximum_line_length{};
  std::string_view file_name{};
  FileCounts& operator+=(const FileCounts &other);
  //l->w->m->c->L
  void print(std::ostream& os, Options const& opt) const;
};