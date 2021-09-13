#include <utl/files.h>
#include <iostream>
#include <crtdbg.h>

int main() {
    std::cout << Files::Absolute_Path("./makefile");
    return 0;
}