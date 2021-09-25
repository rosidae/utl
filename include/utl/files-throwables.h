#define     __FLAG_FILES_THROWABLES
/*
+--------------------+
| files-throwables.h |
+--------------------+
*/
#include    <utl/includes.h>

namespace Files::Throwables {
    class UNUSABLE : std::exception {
    public:
        std::string Name;
        UNUSABLE(
            std::string _Name
        ) { Name = _Name; }
    };
    class NACCESS : std::exception {
    public:
        std::string Name;
        NACCESS(
            std::string _Name
        ) { Name = _Name; }
    };
    class AEXISTS : std::exception {
    public:
        std::string Name;
        AEXISTS(
            std::string _Name
        ) { Name = _Name; }
    };
    class EXCEEDS : std::exception {
    public:
        std::string Name;
        EXCEEDS(
            std::string _Name
        ) { Name = _Name; }
    };
}