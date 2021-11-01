#include <utl/vecs.h>

int main() {
    std::vector<std::string> v = {
        "Hello",
        "World",
        "!",
    };
    for(auto& s : v) {
        std::cout << s << std::endl;
    }
    v = Vecs::Without<std::string>(v, "World");
    for(auto& s : v) {
        std::cout << s << std::endl;
    }
}