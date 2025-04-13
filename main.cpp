#include "MyVector.hpp"
#include "MySwap.hpp"
#include "ContToString.hpp"
#include "MyArrey.hpp"
#include "ContToString.hpp"
#include <iostream>
#include <time.h>
#include <string>

const size_t NumIterations = 1000;
const size_t VecSize = 1000000;

template<typename F>
float MeasureTime(F func){

    clock_t start = clock();
    func();
    clock_t end = clock();

    return  float(end - start)/CLOCKS_PER_SEC;
};

void CopyExample(){
    for (int i = 0; i < NumIterations; ++i){
        MyVector a {VecSize};
        MyVector b = a;
    }
};

void MoveExample(){
    for(int i = 0; i < NumIterations; ++i){
        MyVector a {VecSize};
        MyVector b = std::move (a);
    }
};

int main(){
    
    float CopyTime = MeasureTime(CopyExample);
    float MoveTime = MeasureTime(MoveExample);

    std::cout << "Copy time: " << CopyTime << " s" << std::endl;
    std::cout << "Move time: " << MoveTime << " s" << std::endl;

    std::string a = "string_1";
    std::string b = "string_2";

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    MySwap(a, b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    MyArrey<std::string, 5> arr{};
    
    for (int i = 0; i < arr.GetSize(); ++i){
        arr.At(i) = std::string("str") + std::to_string(i);
    }

    for (int i = 0; i < arr.GetSize(); ++i){
        std::cout << arr.At(i) << std::endl;
    }

    return 0;
}