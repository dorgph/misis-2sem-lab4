#pragma once
#include <string>

template<typename T> std::string ContToString(const T &cont){
    std::string str;
    for (auto iter = cont.cbegin(); iter != cont.cend(); ++iter){
        str += std::to_string(*iter) + " ";
    }

    return str;
}