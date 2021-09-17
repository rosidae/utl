#include <utl/files.h>
#include <iostream>


int main() {
    Files::Find_And_Replace_File("./file.txt", "a", "b");
    return 0;
}