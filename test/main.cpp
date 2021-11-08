#include <utl/extvec.h>
#include <iostream>

int main() {
    extvec<char*> v;
    v.push_back("hello");
    v.push_back("world");
    v.push_back("!");
    v.pop_back();
    for(auto& s : v) {
        std::cout << s << std::endl;
    }
    std::cout << std::boolalpha << v.includes("hello") << std::endl;
    v.clear();
    std::cout << "cleared";
    for(auto& s : v) {
        std::cout << s << std::endl;
    }
}