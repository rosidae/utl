#include <utl/strings.h>

int main() {
    std::string s = "1 1 1 2 3 4 4 3 4";
    std::cout << s << std::endl;
    s = Strings::Find_And_Replace_All(s, "1", "a");
    std::cout << s << std::endl;
}