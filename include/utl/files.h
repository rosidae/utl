/*
+---------+
| files.h |
+---------+
*/
#define     mkdir _mkdir
#define     __FLAG_FILES
#include    <utl/includes.h>
#include    <utl/files-throwables.h>
#ifdef _type_windows
    #include    <direct.h>
#endif

namespace Files {
    bool Usable_File(
        std::string File_Name
    ) {
        std::ifstream File(File_Name);
        if(!File.is_open()) {
            return false;
        }
        File.close();
        return true;
    }
    void Throw_If_Not_Usable(
        std::string File_Name
    ) {
        if(!Usable_File(File_Name)) {
            Throwables::UNUSABLE _Exception(File_Name);
            std::cout << 
                        "File_Name: " << 
                        _Exception.File_Name << 
                        "\n";
            throw _Exception;
        }
    }
    std::string Read_File(
        std::string File_Name
    ) {
        Throw_If_Not_Usable(File_Name);
        std::ifstream   File(File_Name);
        std::string     Line;
        std::string     Text;
        while(!File.eof()) {
            std::getline(File, Line);
            Text += Line;
        }
        File.close();
        return Text;
    }
    std::vector<std::string> Read_File_Lines(
        std::string File_Name
    ) {
        Throw_If_Not_Usable(File_Name);
        std::ifstream               File(File_Name);
        std::string                 Line;
        std::vector<std::string>    Lines;
        while(!File.eof()) {
            std::getline(File, Line);
            Lines.push_back(Line);
        }
        File.close();
        return Lines;
    }
    template <typename T> int Write_File(
        std::string File_Name,
        T           Output,
        bool        Append = false,
        bool        Throw = false
    ) {
        if(Throw) Throw_If_Not_Usable(File_Name);
        std::ofstream File;
        if(Append) {
            File.open(File_Name, std::ios::app);
        } else {
            File.open(File_Name);
        }
        File << Output;
        File.close();
        return 0;
    }
    double Size_Of_File_Double(
        std::string File_Name,
        int         Size_Notation
    ) {
        Throw_If_Not_Usable(File_Name);
        std::ifstream   File(File_Name, std::ios::binary | std::ios::ate);
        double          Size = File.tellg();
        File.close();
        switch (Size_Notation) {
            case 0: return Size/8;
            case 1: return Size/1024;
            case 2: return Size/1024/1024;
            case 3: return Size/1024/1024/1024;
        }
    }
    int Size_Of_File_Int(
        std::string File_Name,
        int         Size_Notation
    ) {
        Throw_If_Not_Usable(File_Name);
        std::ifstream   File(File_Name, std::ios::binary | std::ios::ate);
        int             Size = File.tellg();
        File.close();
        switch (Size_Notation) {
            case 0: return Size/8;
            case 1: return Size/1024;
            case 2: return Size/1024/1024;
            case 3: return Size/1024/1024/1024;
        }
    }
    std::string Head_File(
        std::string File_Name,
        int Count
    ) {
        Throw_If_Not_Usable(File_Name);
        std::string File_Contents = Read_File(File_Name);
        if(File_Contents.size() < Count) {
            throw std::out_of_range(File_Name);
        }
        return File_Contents.substr(0, Count);
    }
}
// WINDOWS ONLY
#ifdef _type_windows
namespace Files {
    void Create_Dir(
        std::string Path
    ) {
        int _Res = mkdir(Path.c_str());
        int _Num;
        if(_Res==-1) {
            _Num = errno;
            std::cout << _Num;
        }
    }
}
#endif