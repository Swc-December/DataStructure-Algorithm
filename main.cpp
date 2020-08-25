//
// Created by ShiJJ on 2020/8/24.
//

#include "Bag.h"
#include <iostream>
#include <fstream>
#include <string>
#include <UnionFind.h>

int main(){
    std::fstream file;
    file.open("../Algorithm/Fundament/data.txt",  std::ios::in);
    std::string line;
    UnionFind union_find(10);
    while (std::getline(file, line)){
        int p, q;
        std::string s1, s2;
        for(int i = 0; i < line.size(); i++){
            if(line[i] == ' '){
                s1 = line.substr(0, 1);
                s2 = line.substr(i+1, 1);
                break;
            }
        }
        p = std::stoi(s1);
        q = std::stoi(s2);
        if(union_find.isConnectedQuick(p, q)){
            std::cout << "is connected" << p << " " << q << std::endl;
        }
        union_find.connectQuick(p, q);
    }
    std::cout << union_find.getConnectNum() << std::endl;

}