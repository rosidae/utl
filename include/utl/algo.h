/*
+--------+
| algo.h |
+--------+
*/
#ifndef     algo_h
    #define algo_h

namespace Algo {
    template<typename T>
    void Swap(
        T& a,
        T& b
    ) {
        T temp = a;
        a = b;
        b = temp;
    }
    template<typename T>
    bool SameVal(
        T* a,
        T* b
    ) {
        return *a == *b;
    }
    template<typename T>
    bool Same(
        T* a,
        T* b
    ) {
        return a==b;
    }
}

#endif // algo_h