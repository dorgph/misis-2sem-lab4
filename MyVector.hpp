#pragma once
#include <utility>
#include <cstddef>

class MyVector{

private:
    int *Data;
    size_t Size;

public:
    MyVector(size_t size): Size{size} {
        Data = new int[Size]{0};
    }

    // Copy constructor
    MyVector(const MyVector &rhs) : MyVector{rhs.Size} {
        for (int i = 0; i < Size; ++i){
            Data[i] = rhs.Data[i];
        }
    }

    // Copy =
    MyVector &operator=(const MyVector &rhs){
        MyVector tmp{rhs};
        std::swap(*this, tmp);

        return *this;
     }

    // Move constructor
    MyVector(MyVector &&rhs) : Size{rhs.Size}, Data{rhs.Data}{
        rhs.Data = nullptr;
    }

    // Move =
    MyVector &operator=(MyVector &&rhs){
        std::swap(Data, rhs.Data);
        std::swap(Size, rhs.Size);

        return *this;
    }

    ~MyVector() {delete[] Data;}
};