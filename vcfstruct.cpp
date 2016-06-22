//
// Created by jameswhang on 6/19/16.
//
#include "vcfstruct.h"
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vcfStruct::match_position(vcfStruct s) {
    typedef map<string, vector<int>>::iterator it;
    typedef vector<int>::iterator vit;

    for (it i = this->info.begin(); i != info.end(); i++) {
        for (vit v = i->second.begin(); v != i->second.end(); v++) {
            if (binary_search(vcf2[i->first].begin(), vcf2[i->first].end(), *v)) {
                oneintwo++;
            } else {
                onenotintwo++;
            }
        }
    }
}

