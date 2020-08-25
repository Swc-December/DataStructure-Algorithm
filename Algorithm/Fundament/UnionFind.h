//
// Created by ShiJJ on 2020/8/25.
//

#ifndef DATASTRUCTURE_ALGORITHM_UNIONFIND_H
#define DATASTRUCTURE_ALGORITHM_UNIONFIND_H

#include <iostream>
#include <vector>
class UnionFind {
private:
    std::vector<int> id;
    int connect_num;
    std::vector<int> node_num;
public:
    UnionFind(int n);
    int find(int q);
    void connect(int p, int q);
    bool isConnected(int p, int q);
    int getConnectNum();

    int findQuick(int q);
    void connectQuick(int p, int q);
    bool isConnectedQuick(int p, int q);
};


#endif //DATASTRUCTURE_ALGORITHM_UNIONFIND_H
