#ifndef     extvec_h
    #define extvec_h
    #include <vector>

template<typename T>
class extvec : public std::vector<T> {
public:
    void push_front(const T& val) {
        this->insert(this->begin(), val);
    }
    void pop_front() {
        this->erase(this->begin());
    }
    bool includes(const T& val) {
        for(T v : *this) {
            if(v == val) {
                return true;
            }
        }
        return false;
    }
    void wipe() {
        this->clear();
    }
};
#endif // extvec_h