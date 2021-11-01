#include <utl/strings.h>

int main() {
    std::cout << Strings::Trim(Strings::Without("a a b b c c d d a a", "a")) << std::endl;
}