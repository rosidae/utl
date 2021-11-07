/*
+--------+
| vecs.h |
+--------+
*/
#ifndef         vecs_h
    #define     vecs_h
    #include    <utl/includes.h>
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
        if(Vec.size() == 0) {
            return std::vector<T>();
        }
        return std::vector<T>{Vec[0]};
    }
    template <typename T> std::vector<T> Tail(
        std::vector<T> Vec
    ) {
        Vec.erase(Vec.begin());
        return _Vec;
    }
    template <typename T> std::vector<T> Last(
        std::vector<T> Vec
    ) {
        return std::vector<T>{Vec[Vec.size()-1]};
    }
    template <typename T> int Indexical_Size(
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
    template <typename T> std::vector<T> Reverse(
        std::vector<T> Vec
    ) {
        std::vector<T> _Result;
        for(int i = Indexical_Size(Vec); i >= 0; i--) {
            _Result.push_back(Vec[i]);
        }
        return _Result;
    }
    template <typename T> std::vector<T> Subset(
        std::vector<T> Vec,
        int            Start,
        int            End
    ) {
        std::vector<T> _Result;
        for(int i = Start; i <= End; i++) {
            _Result.push_back(Vec[i]);
        }
        return _Result;
    }
    template <typename T> std::vector<T> Without(
        std::vector<T> Vec,
        T               To_Remove
    ) {
        std::vector<T> _Result;
        for(T _Val: Vec) {
            if(_Val != To_Remove) {
                _Result.push_back(_Val);
            }
        }
        return _Result;
    }
    template <typename T> std::vector<T> Drop(
        std::vector<T> Vec,
        int            Count
    ) {
        std::vector<T> _Result;
        for(int i = Count; i < Vec.size(); i++) {
            _Result.push_back(Vec[i]);
        }
        return _Result;
    }
    template <typename T> std::vector<T> Unique(
        std::vector<T> Vec
    ) {
        std::vector<T> _Result;
        for(T _Val: Vec) {
            if(!Includes(_Result, _Val)) {
                _Result.push_back(_Val);
            }
        }
        return _Result;
    }
}
#endif // vecs_h