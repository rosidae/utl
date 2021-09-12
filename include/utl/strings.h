#include <utl/includes.h>

namespace Strings {
    std::string Find_And_Replace_All(std::string Original, std::string Find, std::string Replace) {
        char* C_Original = strdup(Original.c_str());
        std::replace(std::cbegin(const_cast(C_Original)), std::cend(const_cast(C_Original)), Find.c_str(), Replace.c_str());
        return C_Original;
    }
}