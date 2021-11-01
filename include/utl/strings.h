#define __FLAG_STRINGS
/*
+-----------+
| strings.h |
+-----------+
*/
#include <utl/includes.h>
#include <regex>

namespace Strings {
    int Indexical_Size(
        std::string String
    ) {
        return String.size() - 1;
    }
    std::string Find_And_Replace_All(
        std::string String,
        std::string Find,
        std::string Replace
    ) {
        std::string Result = String;
        while (Result.find(Find) != std::string::npos) {
            Result.replace(Result.find(Find), Find.size(), Replace);
        }
        return Result;
    }
}