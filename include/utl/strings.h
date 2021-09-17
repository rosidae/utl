#include <utl/includes.h>
#include <regex>

namespace Strings {
    void Find_And_Replace_All(std::string* Original, std::string* Find, std::string* Replace) {
        Original->replace(Original->find(Find->c_str()), sizeof(Find)-1, Replace->c_str());
    }
}