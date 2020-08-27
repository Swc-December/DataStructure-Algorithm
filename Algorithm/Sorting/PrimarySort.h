//
// Created by ShiJJ on 2020/8/26.
//

#ifndef DATASTRUCTURE_ALGORITHM_PRIMARYSORT_H
#define DATASTRUCTURE_ALGORITHM_PRIMARYSORT_H

#include <vector>
#include <iostream>
class PrimarySort {
private:
    std::vector<int> buffer;
public:
    PrimarySort(const std::vector<int> &p);
    void InsertSort(int status);
    void selectSort(int status);
    void printResult();

};


#endif //DATASTRUCTURE_ALGORITHM_PRIMARYSORT_H
