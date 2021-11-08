/*
+--------+
| vecs.h |
+--------+
*/
#ifndef         vecs_h
    #define     vecs_h
    #include    <utl/includes.h>
namespace Vecs {
    /**
     * @brief Tells if a vector includes a value<T>
     * 
     * @tparam T
     * @param Vec The vector to search in
     * @param Search The value to search for
     * @return true 
     * @return false 
     */
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
    /**
     * @brief Get the first index of a vector
     * 
     * @tparam T 
     * @param Vec The vector to get the head of
     * @return std::vector<T> 
     */
    template <typename T> std::vector<T> Head(
        std::vector<T> Vec
    ) {
        if(Vec.size() == 0) {
            return std::vector<T>();
        }
        return std::vector<T>{Vec[0]};
    }
    /**
     * @brief Get the tail of a vector
     * 
     * @tparam T 
     * @param Vec 
     * @return std::vector<T> 
     */
    template <typename T> std::vector<T> Tail(
        std::vector<T> Vec
    ) {
        Vec.erase(Vec.begin());
        return _Vec;
    }
    /**
     * @brief Get the last index of a vector
     * 
     * @tparam T 
     * @param Vec The vector to get the last index of
     * @return std::vector<T> 
     */
    template <typename T> std::vector<T> Last(
        std::vector<T> Vec
    ) {
        if(Vec.size() == 0) {
            return std::vector<T>();
        }
        return std::vector<T>{Vec[Vec.size()-1]};
    }
    /**
     * @brief Gets the amount of matches in a vector
     * 
     * @tparam T 
     * @param Vec The vector to search in
     * @param To_Match The value to search for and return the count of matches for
     * @return int 
     */
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
    /**
     * @brief Tells if two vectors have equal values
     * 
     * @tparam T 
     * @param Origin 
     * @param Compare 
     * @return true 
     * @return false 
     */
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
    /**
     * @brief Concatenates two vectors together
     * 
     * @tparam T 
     * @param First The Beginning vector
     * @param Last The Tailing vector
     * @return std::vector<T> 
     */
    template <typename T> std::vector<T> Concatenate(
        std::vector<T> First,
        std::vector<T> Last
    ) {
        std::vector<T> _Result;
        for(T _Val: First) _Result.push_back(_Val);
        for(T _Val: Last) _Result.push_back(_Val);
        return _Result;
    }
    /**
     * @brief Reverses the order of a vector
     * 
     * @tparam T 
     * @param Vec The vector to reverse
     * @return std::vector<T> 
     */
    template <typename T> std::vector<T> Reverse(
        std::vector<T> Vec
    ) {
        std::vector<T> _Result;
        for(T _Val: Vec) _Result.insert(_Result.begin(), _Val);
        return _Result;
    }
    /**
     * @brief Gets a subsection of a vector
     * 
     * @tparam T 
     * @param Vec The vector to get a subsection of
     * @param Start The starting index
     * @param End The ending index
     * @return std::vector<T> 
     */
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
    /**
     * @brief Returns a vector without To_Remove
     * 
     * @tparam T 
     * @param Vec The vector to remove from
     * @param To_Remove The value to remove
     * @return std::vector<T> 
     */
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
    /**
     * @brief Gets a vector that has no repeating values
     * 
     * @tparam T 
     * @param Vec The vector to remove repeating values from 
     * @return std::vector<T> 
     */
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