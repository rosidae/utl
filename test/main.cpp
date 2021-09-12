#include <utl/files.h>

int main() {
    Files::Find_And_Replace_File("./file.txt", "Finding", "Replacing");
    return 0;
}