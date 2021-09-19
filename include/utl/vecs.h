#include <utl/includes.h>
namespace Vecs {
    template <typename T>
    bool Includes(
        std::vector<T>  Vec,
        T               Search
    ) {
        for(T v: Vec) {
            if(v == Search) {
                return true;
            }
        }
        return false;
    }
    template <typename T>
    std::vector<T> Head(
        std::vector<T> Vec
    ) {
        return std::vector<T>{Vec[0]};
    }
    template <typename T>
    std::vector<T> Tail(
        std::vector<T> Vec
    ) {
        std::vector<T> Vec_;
        for (int I = 1; I < Vec.size(); I++)
        {
            Vec_.push_back(Vec[I]);
        }
        return Vec_;
    }
}