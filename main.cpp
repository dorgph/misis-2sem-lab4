#include "MyVector.hpp"
#include <iostream>
#include <time.h>

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
    return 0;
}