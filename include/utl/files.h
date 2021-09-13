#include <utl/includes.h>
#include <utl/strings.h>

namespace Files {
    std::string Read_File(std::string File_Name) {
        std::ifstream File(File_Name);
        std::string Text;
        if(!File.is_open()) {
            return "";
        }
        File >> Text;
        File.close();
        return Text;
    }
    std::vector<std::string> Read_File_Lines(std::string File_Name) {
        std::ifstream File(File_Name);
        std::string Line;
        std::vector<std::string> Lines;
        if(!File.is_open()) {
            return std::vector<std::string>{""};
        }
        while(!File.eof()) {
            std::getline(File, Line);
            Lines.push_back(Line);
        }
        File.close();
        return Lines;
    }
    int Write_File(std::string File_Name, std::string Output, bool Append = false) {
        std::ofstream File;
        if(Append) {
            File.open(File_Name, std::ios::app);
        } else {
            File.open(File_Name);
        }
        if(File.fail()) {
            return -1;
        }
        File << Output;
        return 0;
    }
    int Find_And_Replace_File(std::string File_Name, std::string Find, std::string Replace) {
        std::string Content = Read_File(File_Name);
        Strings::Find_And_Replace_All(Content, Find, Replace);
        Write_File(File_Name, Content);
        return 0;
    }
}