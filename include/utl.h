#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>

namespace files {
    std::string read(std::string fn) {
        std::ifstream file(fn);
        char* text;
        if(!file.is_open()) {
            return "";
        }
        file >> text;
        return text;
    }
    std::vector<std::string> readlines(std::string fn) {
        std::ifstream file(fn);
        std::string line;
        std::vector<std::string> lines;
        if(!file.is_open()) {
            return std::vector<std::string>{""};
        }
        while(!file.eof()) {
            std::getline(file, line);
            lines.push_back(line);
        }
        file.close();
        return lines;
    }
    int write(std::string fn, std::string output, bool append = false) {
        std::ofstream file;
        if(append) {
            file.open(fn, std::ios::app);
        } else {
            file.open(fn);
        }
        if(file.fail()) {
            return -1;
        }
        file << output;
        return 0;
    }
}