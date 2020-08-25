//
// Created by ShiJJ on 2020/8/25.
//

#include "UnionFind.h"

UnionFind::UnionFind(int n)
: connect_num(n){
    for(int i = 0; i < n; i++){
        id.push_back(i);
        node_num.push_back(1);
    }
}

int UnionFind::find(int q) {
    return id[q];
}

void UnionFind::connect(int p, int q) {
    if(id[p] == id[q]){
        return;
    }
    int id_p = find(p);
    int id_q = find(q);
    for(int & i : id){
        if(i == id_q){
            i = id_p;
        }
    }
    connect_num--;
}

bool UnionFind::isConnected(int p, int q) {
    return find(q) == find(p);
}

int UnionFind::getConnectNum() {
    return connect_num;
}

int UnionFind::findQuick(int q) {
    while (id[q] != q){
        q = id[q];
    }
    return id[q];

}

void UnionFind::connectQuick(int p, int q) {
    int p_root = findQuick(p);
    int q_root = findQuick(q);
    if(p_root == q_root){
        return;
    }
    if(node_num[p_root] > node_num[q_root]){
        id[q_root] = p_root;
        node_num[p_root] += node_num[q_root];
    } else {
        id[p_root] = q_root;
        node_num[q_root] += node_num[p_root];
    }

    connect_num--;

}

bool UnionFind::isConnectedQuick(int p, int q) {
    return findQuick(p) == findQuick(q);
}