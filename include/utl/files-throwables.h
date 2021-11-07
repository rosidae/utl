/*
+--------------------+
| files-throwables.h |
+--------------------+
*/
#ifndef         files_throwables_h
    #define     files_throwables_h
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
#endif // files_throwables_h
