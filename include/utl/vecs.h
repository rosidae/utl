#include <utl/includes.h>
// Due to the use of template typedefs
// we are unable to use pointers because to use a pointer
// the datatype needs to be known at COMPILATION time

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
        std::vector<T> _Vec;
        for (int I = 1; I < Vec.size(); I++)
        {
            _Vec.push_back(Vec[I]);
        }
        return _Vec;
    }
    template <typename T>
    std::vector<T> Last(
        std::vector<T> Vec
    ) {
        return std::vector<T>{Vec[Vec.size()-1]};
    }
    template <typename T>
    std::vector<T> Indexical_Size(
        std::vector<T> Vec
    ) {
        return Vec.size()-1;
    }
    template <typename T>
    int Match_Count(
        std::vector<T>  Vec,
        T               To_Match
    ) {
        int _Count = 0;
        for(T _Val: Vec) {
            _Count += _Val == To_Match;
        }
        return _Count;
    }

}