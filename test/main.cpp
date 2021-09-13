#include <utl/files.h>

int main() {
    std::cout << Files::Find_And_Replace_File("./file.txt", "a", "b");
    return 0;
}