#include <cassert>

template<typename T, size_t N> class MyArrey{

private:
    T Data[N] = {};

public:
    MyArrey() = default;

    T &At(size_t i){
        assert(i < N);
        return Data[i];
    }

    const T &At(size_t i) const {
        assert(i < N);
        return Data[i];
    }

    size_t GetSize() const {return N;}

};