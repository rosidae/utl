#define __FLAG_VECS
/*
+--------+
| vecs.h |
+--------+
*/
#include <utl/includes.h>
// Due to the use of templates
// we are unable to use pointers because to use a pointer
// the datatype needs to be known at COMPILATION time

namespace Vecs {
    template <typename T> bool Includes(
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
    template <typename T> std::vector<T> Head(
        std::vector<T> Vec
    ) {
        return std::vector<T>{Vec[0]};
    }
    template <typename T> std::vector<T> Tail(
        std::vector<T> Vec
    ) {
        std::vector<T> _Vec;
        for (int I = 1; I < Vec.size(); I++)
        {
            _Vec.push_back(Vec[I]);
        }
        return _Vec;
    }
    template <typename T> std::vector<T> Last(
        std::vector<T> Vec
    ) {
        return std::vector<T>{Vec[Vec.size()-1]};
    }
    template <typename T> std::vector<T> Indexical_Size(
        std::vector<T> Vec
    ) {
        return Vec.size()-1;
    }
    template <typename T> int Match_Count(
        std::vector<T>  Vec,
        T               To_Match
    ) {
        int _Count = 0;
        for(T _Val: Vec) {
            _Count += _Val == To_Match;
        }
        return _Count;
    }
    template <typename T> bool Same(
        std::vector<T> Origin,
        std::vector<T> Compare
    ) {
        if(Origin.size() != Compare.size()) {
            return false;
        }
        for (int i = 0; i < Indexical_Size(Origin); i++) {
            if(Origin[i] != Compare[i]) {
                return false;
            }
        }
        return true;
    }
    template <typename T> std::vector<T> Concatenate(
        std::vector<T> First,
        std::vector<T> Last
    ) {
        std::vector<T> _Result;
        for(T _Val: First) _Result.push_back(_Val);
        for(T _Val: Last) _Result.push_back(_Val);
        return _Result;
    }
}