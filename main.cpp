#include <exception>
#include <iostream>
#include <string_view>
#include "src/Options.h"
#include "src/Counter.h"
#include "src/Filecounter.h"

auto help_text = ""; // TODO, fill in with real help text, copied from `wc --help`

int main(int argc, char * argv[]){
  try
  {
    Options opts{argc, argv};

    if (opts.verbose()){
      // print parsed options
       opts.print(std::cout);
    }

    if (opts.help()){
      std::cout << help_text;
      return EXIT_SUCCESS;
    }

    if (opts.version()){
      std::cout << "Copyright (C) 2026 Free Software Foundation, Inc.\
      License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\
      This is free software: you are free to change and redistribute it.\
      There is NO WARRANTY, to the extent permitted by law.\
      \
      Written by Luk.";
      return EXIT_SUCCESS;
    }
    
    if (opts.file_names().empty())
    {
      std::cout << "No file names passed.\n";
      std::cout << "Try `wc --help` for more information.\n";
      return EXIT_FAILURE;
    }

    Counter counter{};
    // TODO: handle summing up totals in the loop below
    FileCounts totals{};
    totals.file_name = "total";
    for (const auto &file_name : opts.file_names())
    {
      auto counts = counter.process(file_name);
      counts.print(std::cout, opts);
      totals+=counts;
    }
    totals.print(std::cout, opts);
    // TODO: print totals if mor than one file processed


    return EXIT_SUCCESS;
  }
  catch(const std::exception& exc){
    std::cout << exc.what() << '\n';
    std::cout << "Try `wc --help` for more information.\n";
    return EXIT_FAILURE;
  }
}