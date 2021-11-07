/*
+-----------+
| strings.h |
+-----------+
*/
#ifndef         strings_h
    #define     strings_h
    #include    <utl/includes.h>
    #include    <regex>

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
    bool Includes(
        std::string String,
        std::string Find
    ) {
        return String.find(Find) != std::string::npos;
    }
    std::string Head(
        std::string String,
        int Length
    ) {
        std::string Result = String;
        if (Length > Result.size()) {
            Length = Result.size();
        }
        Result.erase(Length);
        return Result;
    }
    std::string Alternating_Case(
        std::string String
    ) {
        std::string Result = String;
        for (int i = 0; i < Result.size(); i++) {
            if (i % 2 == 0) {
                Result[i] = std::toupper(Result[i]);
            } else {
                Result[i] = std::tolower(Result[i]);
            }
        }
        return Result;
    }
    std::string Without(
        std::string String,
        std::string Find
    ) {
        std::string Result = String;
        while (Result.find(Find) != std::string::npos) {
            Result.erase(Result.find(Find), Find.size());
        }
        return Result;
    }
    bool Pointer_Value_Equal(
        std::string* String_1,
        std::string* String_2
    ) {
        return *String_1 == *String_2;
    }
    bool Pointer_Equal(
        std::string* String_1,
        std::string* String_2
    ) {
        return String_1 == String_2;
    }
}
#endif // strings_h