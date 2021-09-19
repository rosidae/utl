#include <utl/vecs.h>
#include <string>

int main() {
    std::vector<int> v{1,1,1,1,1,1,4,5};
    std::cout << Vecs::Match_Count(v, 1);
}