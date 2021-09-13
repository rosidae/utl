#include <utl/includes.h>

namespace Strings {
    std::string Find_And_Replace_All(std::string Original, std::string Find, std::string Replace) {
        std::string New = Original;
        New.replace(New.begin(), New.begin() + New.find(Find), Replace);
        return New;
    }
}