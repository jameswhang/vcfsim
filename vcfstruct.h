//
// Created by jameswhang on 6/19/16.
//

#ifndef VCF_SIM_VCFSTRUCT_H
#define VCF_SIM_VCFSTRUCT_H
#include <vector>
#include <map>

using namespace std;

class vcfStruct{
    bool matchChromosome;  // match the chromosome number
    bool matchPosiiton;  // match the SNP position
    bool matchMutation;  // match the specific mutation

public:
    map<string, vector<int>> info;

    // Returns the # of matching lines
    int match_positions(vcfStruct s);
};

#endif //VCF_SIM_VCFSTRUCT_H
