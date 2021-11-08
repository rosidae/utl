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
    /**
     * @brief Preformes a find and replace on a string.
     * 
     * @param String The string to perform the find and replace on.
     * @param Find The string to find.
     * @param Replace The string to replace the found string with.
     * @return std::string 
     */
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
    /**
     * @brief Preformes a find and replace on a string but only replaces the first match.
     * 
     * @param String The string to perform the find and replace on.
     * @param Find The string to find.
     * @param Replace The string to replace the found string with.
     * @return std::string 
     */
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
    /**
     * @brief Preformes a find and replace on a string but only replaces the last match.
     * 
     * @param String The string to perform the find and replace on.
     * @param Find The string to find.
     * @param Replace The string to replace the found string with.
     * @return std::string 
     */
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
    /**
     * @brief Reverses a string.
     * 
     * @param String The string to reverse.
     * @return std::string 
     */
    std::string Reverse(
        std::string String
    ) {
        std::string Result = String;
        std::reverse(Result.begin(), Result.end());
        return Result;
    }
    /**
     * @brief Converts every character in a string to lowercase.
     * 
     * @param String The string to convert to lowercase.
     * @return std::string 
     */
    std::string To_Lower(
        std::string String
    ) {
        std::string Result = String;
        std::transform(Result.begin(), Result.end(), Result.begin(), ::tolower);
        return Result;
    }
    /**
     * @brief Converts every character in a string to uppercase.
     * 
     * @param String The string to convert to uppercase.
     * @return std::string 
     */
    std::string To_Upper(
        std::string String
    ) {
        std::string Result = String;
        std::transform(Result.begin(), Result.end(), Result.begin(), ::toupper);
        return Result;
    }
    /**
     * @brief Trims a string.
     * 
     * @param String The string to trim.
     * @return std::string 
     */
    std::string Trim(
        std::string String
    ) {
        std::string Result = String;
        Result.erase(0, Result.find_first_not_of(' '));
        Result.erase(Result.find_last_not_of(' ') + 1);
        return Result;
    }
    /**
     * @brief Trims a string from the left.
     * 
     * @param String The string to trim.
     * @return std::string 
     */
    std::string Trim_Left(
        std::string String
    ) {
        std::string Result = String;
        Result.erase(0, Result.find_first_not_of(' '));
        return Result;
    }
    /**
     * @brief Trims a string from the right.
     * 
     * @param String The string to trim.
     * @return std::string 
     */
    std::string Trim_Right(
        std::string String
    ) {
        std::string Result = String;
        Result.erase(Result.find_last_not_of(' ') + 1);
        return Result;
    }
    /**
     * @brief Returns true if a string includes Find
     * 
     * @param String The string to search.
     * @param Find The string to search for.
     * @return true 
     * @return false 
     */
    bool Includes(
        std::string String,
        std::string Find
    ) {
        return String.find(Find) != std::string::npos;
    }
    /**
     * @brief Gets the first Length characters of a string.
     * 
     * @param String The string to get the first characters from.
     * @param Length The number of characters to get.
     * @return std::string 
     */
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
    /**
     * @brief Returns a string without the found string.
     * 
     * @param String The string to remove the found string from.
     * @param Find The string to remove.
     * @return std::string 
     */
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
}
#endif // strings_h