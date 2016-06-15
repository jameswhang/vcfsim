//
// Created by jameswhang on 6/15/16.
//

#ifndef VCF_SIM_VCFPARSER_H
#define VCF_SIM_VCFPARSER_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class vcfparser {
public:
    void readfile(string filepath, map<string, vector<int>> * vcfmap);
};
#endif //VCF_SIM_VCFPARSER_H
