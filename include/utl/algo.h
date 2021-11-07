/*
+--------+
| algo.h |
+--------+
*/
#ifndef     algo_h
    #define algo_h

namespace Algo {
    template<class T>
    void Swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    
}

#endif // algo_h