#include <utl/includes.h>
namespace Vecs {
    template <typename T>
    bool Includes(
        std::vector<T> Vec,
        T Search
    ) {
        for(T v: Vec) {
            if(v == Search) {
                return true;
            }
        }
        return false;
    }
}