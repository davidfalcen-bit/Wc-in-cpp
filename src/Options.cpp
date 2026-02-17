#include "Options.h"
#include <cstddef>
#include <stdexcept>
#include <string>
/*  -c, --bytes
       print the byte counts
-m, --chars
       print the character counts
-l, --lines
       print the newline counts
-L, --max-line-length
       print the maximum display width
-w, --words
       print the word counts
    --help
       display this help and exit
 */

void Options::parse(int argc, char * argv[]){
    for(int j = 1; j < argc; j++){
        std::string temp{argv[j]};
        if(temp == "-") file_names_.push_back("stdin");
        else if(temp.starts_with("--")){
            if(temp == "--bytes") bytes_ = true;
            else if(temp == "--chars") characters_ = true;
            else if(temp == "--words") words_ = true;
            else if(temp == "--lines") lines_ = true;
            else if (temp == "--max-line-length") longest_line_ = true;
            else if(temp == "--help") help_ = true;
            else if(temp == "--verbose") verbose_ = true;
            else if(temp == "--version") version_ = true;
            else throw std::invalid_argument(std::string("Unknown option: ") + temp);
        }
        else if(temp.front() == '-'){
            for (size_t i = 1; i < temp.size(); i++){
                if(temp[i] == 'c') bytes_ = true;
                else if(temp[i] == 'm') characters_ = true;
                else if(temp[i] == 'l') lines_ = true;
                else if(temp[i] == 'L') longest_line_ = true;
                else if(temp[i] == 'w') words_ = true;
                else throw std::invalid_argument(std::string("Unknown option: ") + temp); 
            }
        }
        else file_names_.push_back(argv[j]);
    }
}

const std::vector<std::string>& Options::file_names() const{
    return file_names_;
}

Options::Options(int argc, char * argv[]){
    parse(argc, argv);
}

bool Options::lines() const{return lines_;};
bool Options::words() const{return words_;};
bool Options::characters() const{return characters_;};
bool Options::bytes() const{return bytes_;};
bool Options::longest_line() const{return longest_line_;};
bool Options::help() const{return help_;};
bool Options::version() const{return version_;};
bool Options::verbose() const{return verbose_;}

void Options::print(std::ostream &os)const{
    os << *this; 
}