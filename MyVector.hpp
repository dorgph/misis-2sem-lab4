#pragma once
#include <utility>

class MyVector{

private:
    int *Data;
    size_t Size;

public:
    MyVector(size_t size): Size{size}; {Data = new int[Size]{0}; }

    // Copy constructor
    MyVector(const Myvector &rhs) : MyVector{rh.sSyze} {
        for (int i = 0; i < Size; ++i){
            Data[i] = rhs.Data[i];
        }
    }

    // Copy =
    MyVector &operator=(const MyVector &rhs){
        MyVector tmp{rhs};
        std::swap(*this, rhs);

        return *this;
     }

    // Move constructor
    MyVector(Myvector &&rhs) : Size{rhs.Size}, Data{rhs.Data}{
        rhs.Data = nullptr;
    }

    // Move =
    MyVector &operator=(MyVector &&rhs){
        std::swap(Data, rhs.Data);
        std::swap(Size, rha.Size);

        return *this;
    }

    ~MyVecstor() {delete[] Data;}
};