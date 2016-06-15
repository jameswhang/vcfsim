#include <iostream>
#include <map>
#include <vector>
#include "vcfparser.h"

using namespace std;

int main() {
    vcfparser parser;
    map<string, vector<int>> vcf1;
    map<string, vector<int>> vcf2;

    parser.readfile("/Users/jameswhang/ClionProjects/vcf-sim/SSHR1T_normal.haplotype.vcf", &vcf1);
    parser.readfile("/Users/jameswhang/ClionProjects/vcf-sim/SSHR1T_tumor.haplotype.vcf", &vcf2);


    int oneintwo = 0;
    int onenotintwo = 0;
    int twoinone = 0;
    int twonotinone = 0;

    typedef map<string, vector<int>>::iterator it;
    typedef vector<int>::iterator vit;

    for (it i = vcf1.begin(); i != vcf1.end(); i++) {
        for (vit v = i->second.begin(); v != i->second.end(); v++) {
            if (binary_search(vcf2[i->first].begin(), vcf2[i->first].end(), v)) {
                oneintwo++;
            } else {
                onenotintwo++;
            }
        }
    }

    for (it i = vcf2.begin(); i != vcf2.end(); i++) {
        for (vit v = i->second.begin(); v != i->second.end(); v++) {
            if (binary_search(vcf1[i->first].begin(), vcf1[i->first].end(), v)) {
                twoinone++;
            } else {
                twonotinone++;
            }
        }
    }

    cout << "# of lines of vcf1 in vcf2: " << oneintwo << endl;
    cout << "# of lines of vcf1 not in vcf2: " << onenotintwo << endl;
    cout << "# of lines of vcf2 in vcf1: " << twoinone << endl;
    cout << "# of lines of vcf2 not in vcf1: " << twonotinone << endl;


    return 0;
}