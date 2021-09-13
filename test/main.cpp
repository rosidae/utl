#include <utl/files.h>

int main() {
    std::cout << Files::Size_Of_File_Int("test.exe", FILE_SIZE_KILOBYTES);
    return 0;
}