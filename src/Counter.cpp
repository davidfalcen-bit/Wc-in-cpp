#include "Counter.h"
#include "Filecounter.h"
#include "Options.h"
#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>
#include <string_view>

Counter::Counter(const Options& opts) : opts(opts) {}


size_t char_counter(const std::string_view line){
    size_t count{0};
    for(unsigned char c : line){
        if((c&0xC0)!= 0x80) count++;
    }
    return count;
}

size_t word_counter(const std::string_view line){
    bool in_word{false};
    size_t count{0};
    for(unsigned char x:line){
        if(!in_word && !isspace(x)){
            count++;
            in_word = true;
        }else if (isspace(x)) in_word = false;
    }
    return count;
}

FileCounts Counter::process(const std::string &file_name){
    FileCounts co{};
    co.file_name = file_name;
    std::string buffer{};
    std::istream *input_stream = nullptr;
    std::ifstream file;
    if(file_name == "stdin") input_stream = &(std::cin);
    else{
        file.open(file_name);
        if(!file) throw std::invalid_argument("Not existing file");
        input_stream = &file;
    }
    
    while (std::getline(*input_stream, buffer)) {
        co.lines++;
        auto temp_count = char_counter(buffer);
        co.characters += temp_count+1;
        if(temp_count > co.maximum_line_length) co.maximum_line_length = temp_count;
        co.bytes += buffer.size()+1;
        co.words += word_counter(buffer);
    }
    return co;
}



