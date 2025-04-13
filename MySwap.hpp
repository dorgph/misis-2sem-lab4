


template<typename T> void MySwap(T &a, T &b){
    T c {std::move(a)};
    a = std::move(b);
    b = std::move(c);
}