#include <utl/includes.h>
#include <regex>

namespace Strings {
    std::string Find_And_Replace_All(std::string Original, std::string Find, std::string Replace) {
        return std::regex_replace(Original, std::regex(Find.c_str()), Replace);
    }
}