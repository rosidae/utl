#include <utl.h>

int main() {
    for(std::string line : files::readlines("../README.md")) {
        std::cout << line << "\n";
    }
    return 0;
}