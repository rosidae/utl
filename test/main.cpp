#include <utl/vecs.h>
#include <string>

int main() {
    std::vector<std::string> v{"11","15","612","62","1337"};
    std::cout << Vecs::Includes(v, (std::string)"1");
}