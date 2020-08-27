//
// Created by ShiJJ on 2020/8/26.
//

#include "PrimarySort.h"

PrimarySort::PrimarySort(const std::vector<int> &p) {
    buffer = std::vector<int>(p);
//    for(auto p :buffer){
//        std::cout << p << std::endl;
//    }
}

void PrimarySort::selectSort(int status) {

    auto ascend = [](int a, int b) -> int { return a > b;};
    auto descend = [](int a, int b) -> int { return a < b;};
    auto compare = status == 0 ? ascend : descend;

    for(int i = 0; i < buffer.size(); i++){
        int choose = buffer[i];
        int choose_idx = i;
        for(int j = i+1; j < buffer.size(); j++){
            if(compare(choose, buffer[j])){
                choose = buffer[j];
                choose_idx = j;
            }
        }
        int temp = buffer[i];
        buffer[i] = buffer[choose_idx];
        buffer[choose_idx] = temp;
    }

}

void PrimarySort::printResult() {
    std::cout << "[ ";
    for(int i = 0; i < buffer.size(); i++){
        if(i != buffer.size() - 1){
            std::cout << buffer[i] << ", ";
        } else {
            std::cout << buffer[i] << " ]";
        }

    }
}

void PrimarySort::InsertSort(int status) {
    auto ascend = [](int a, int b) -> int {return a > b;};
    auto descend = [](int a, int b) -> int { return a < b;};
    auto compare = status == 0 ? ascend : descend;
    for(int i = 1; i < buffer.size(); i++){
        for(int j = 0; j < i; j++){
            if(compare(buffer[j], buffer[i])){
                int temp = buffer[i];
                for(int k = i; k > j; k--){
                    buffer[k] = buffer[k - 1];
                }
                buffer[j] = temp;
                break;
            }
        }
    }
}