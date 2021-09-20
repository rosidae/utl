#include <utl/files.h>
#include <string>

int main() {
    std::cout << Files::Head_File("./file.txt", 52);
}