#include "Filecounter.h"
#include "Options.h"

void FileCounts::print(std::ostream& os, Options const& opt) const{
    if(opt.lines()) os<<lines;
    if(opt.words()) os<<"\t"<<words;
    if(opt.characters()) os<<"\t"<<characters;
    if(opt.bytes()) os<<"\t"<<bytes;
    if(opt.longest_line()) os<<"\t"<<maximum_line_length;
    os<<"\t"<< file_name <<"\n";
}

FileCounts& FileCounts::operator+=(const FileCounts &other){
    words+=other.words;
    bytes+=other.bytes;
    characters+=other.characters;
    lines+=other.lines;
    maximum_line_length = std::max(maximum_line_length, other.maximum_line_length);
    return *this;
}