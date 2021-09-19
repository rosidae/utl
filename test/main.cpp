#include <utl/vecs.h>
#include <string>

int main() {
    std::vector<int> v{1,2,3,4};
    for(int a: Vecs::Tail(v)) {
        std::cout << a << "\n";
    }
}