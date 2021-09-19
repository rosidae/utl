#include <utl/vecs.h>
#include <string>

int main() {
    std::vector<int> v{1,1,1,1,1,1,4,5};
    std::vector<int> a{1238,321,321};
    for(int val: Vecs::Concatenate(v,a)) {
        std::cout << val << "\n";
    }
}