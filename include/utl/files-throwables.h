#include <utl/includes.h>
#include <sys/stat.h>
#include <sys/types.h>

namespace Files::Throwables {
    class UNUSABLE : std::exception {
    public:
        std::string File_Name;
        UNUSABLE(
            std::string _File_Name
        ) { File_Name = _File_Name; }
    };
    class NACCESS : std::exception {
    public:
        std::string File_Name;
        NACCESS(
            std::string _File_Name
        ) { File_Name = _File_Name; }
    };
    class AEXISTS : std::exception {
    public:
        std::string File_Name;
        AEXISTS(
            std::string _File_Name
        ) { File_Name = _File_Name; }
    };
}