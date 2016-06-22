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
private:
    int version;
    int num_lines;

public:
    // TODO 1: Add more methods to parse each field inside vcf file
    // TODO 2: Add a way to parse different VCF version files
    void readfile(string filepath, map<string, vector<int>> * vcfmap);

    void setVersion(int ver);
};
#endif //VCF_SIM_VCFPARSER_H
