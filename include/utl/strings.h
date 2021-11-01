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
    std::string Find_And_Replace_First(
        std::string String,
        std::string Find,
        std::string Replace
    ) {
        std::string Result = String;
        if (Result.find(Find) != std::string::npos) {
            Result.replace(Result.find(Find), Find.size(), Replace);
        }
        return Result;
    }
    std::string Find_And_Replace_Last(
        std::string String,
        std::string Find,
        std::string Replace
    ) {
        std::string Result = String;
        if (Result.rfind(Find) != std::string::npos) {
            Result.replace(Result.rfind(Find), Find.size(), Replace);
        }
        return Result;
    }
    std::string Reverse(
        std::string String
    ) {
        std::string Result = String;
        std::reverse(Result.begin(), Result.end());
        return Result;
    }
    std::string To_Lower(
        std::string String
    ) {
        std::string Result = String;
        std::transform(Result.begin(), Result.end(), Result.begin(), ::tolower);
        return Result;
    }
    std::string To_Upper(
        std::string String
    ) {
        std::string Result = String;
        std::transform(Result.begin(), Result.end(), Result.begin(), ::toupper);
        return Result;
    }
    std::string Trim(
        std::string String
    ) {
        std::string Result = String;
        Result.erase(0, Result.find_first_not_of(' '));
        Result.erase(Result.find_last_not_of(' ') + 1);
        return Result;
    }
    std::string Trim_Left(
        std::string String
    ) {
        std::string Result = String;
        Result.erase(0, Result.find_first_not_of(' '));
        return Result;
    }
    std::string Trim_Right(
        std::string String
    ) {
        std::string Result = String;
        Result.erase(Result.find_last_not_of(' ') + 1);
        return Result;
    }
}