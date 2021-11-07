#include <utl/strings.h>

int main() {
    std::string a1 = "Hello, world!";
    std::string* a2 = &a1;
    std::string b1 = "Hello, world!";
    std::string* b2 = &b1;
    std::cout << std::boolalpha << "Value_Equal:" << Strings::Pointer_Value_Equal(a2, b2) << "\nEqual:" << Strings::Pointer_Equal(a2, b2) << std::endl;
}