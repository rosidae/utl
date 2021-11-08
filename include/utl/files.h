/*
+---------+
| files.h |
+---------+
*/
#ifndef         files_h
    #define     files_h
    #include    <utl/includes.h>
#include        <utl/files-throwables.h>
#ifdef _type_windows
    #include    <direct.h>
    #define     mkdir\
               _mkdir
#endif // _type_windows

namespace Files {
    /**
     * @brief Tells whether a file is usable or not.
     * 
     * @param File_Name The name of the file to check. 
     * @return true The file exists and is usable.
     * @return false The file does not exist or is not usable.
     */
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
                        _Exception.Name << 
                        "\n";
            throw _Exception;
        }
    }
    /**
     * @brief Reads a file and returns its contents as a string.
     * 
     * @param File_Name The name of the file to read.
     * @return std::string The contents of the file.
     */
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
    /**
     * @brief Overwrites a T to a file.
     * 
     * @tparam T The type of the object to write.
     * @param File_Name Name of the file to write to.
     * @param Write The object to write. 
     * @param Append Whether to append to the file or overwrite it.
     * @param Throw Whether to throw an exception if the file cannot be written to or not.
     * @return int Success or failure.
     */
    template <typename T> int Write_File(
        std::string File_Name,
        T           Write,
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
        File << Write;
        File.close();
        return 0;
    }
    /**
     * @brief Get the size of a file.
     * 
     * @param File_Name The name of the file to get the size of.
     * @param Size_Notation The notation to use for the size.
     * @return double Size of the file in the specified notation.
     */
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
    /**
     * @brief Get the size of a file.
     * 
     * @param File_Name The name of the file to get the size of.
     * @param Size_Notation The notation to use for the size.
     * @return int The size of the file in the specified notation.
     */
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
    /**
     * @brief Get the first Count characters of a file.
     * 
     * @param File_Name The name of the file to get the first characters of.
     * @param Count The number of characters to get.
     * @return std::string 
     */
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
    /**
     * @brief Find and replace all instances of a string in a file.
     * 
     * @param File_Name The name of the file to find and replace in.
     * @param Find The string to find.
     * @param Replace The string to replace the found string(s) with.
     * @return std::string The contents of the file with the replacements.
     */
    std::string Find_And_Replace_All_File(
        std::string File_Name,
        std::string Find,
        std::string Replace
    ) {
        Throw_If_Not_Usable(File_Name);
        std::string File_Contents = Read_File(File_Name);
        std::string New_File_Contents = File_Contents;
        while(New_File_Contents.find(Find) != std::string::npos) {
            New_File_Contents.replace(
                New_File_Contents.find(Find),
                Find.size(),
                Replace
            );
        }
        Write_File(File_Name, New_File_Contents);
        return New_File_Contents;
    }
}
// WINDOWS ONLY
#ifdef _type_windows
namespace Files {
    /**
     * @brief Create a directory.
     * 
     * @param Path The path of the directory to create.
     */
    void Create_Dir(
        std::string Path
    ) {
        int _Res = mkdir(Path.c_str());
        int _Num;
        if(_Res==-1) {
            _Num = errno;
            Throwables::AEXISTS _EEXIST(Path);
            Throwables::NACCESS _ENONET(Path);
            switch (_Num) {
                case EEXIST:
                    std::cout << _EEXIST.Name << "\n";
                    throw _EEXIST;
                    break;
                case ENOENT:
                    std::cout << _ENONET.Name << "\n";
                    throw _ENONET;
                    break;
                
            }
        }
    }
}
#endif // _type_windows
#endif // files_h