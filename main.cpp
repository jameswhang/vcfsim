#include <iostream>
#include <map>
#include <vector>
#include "vcfparser.h"

using namespace std;

int main(int argc, char * argv[]) {

    if (argc < 3) {
        cout << "Usage: vcfsim [path to vcf 1] [path to vcf 2]" << endl;
        exit(1);
    }

    string vcf1_path = argv[1];
    string vcf2_path = argv[2];

    vcfparser parser;
    map<string, vector<int>> vcf1;
    map<string, vector<int>> vcf2;

    parser.readfile(vcf1_path, &vcf1);
    parser.readfile(vcf2_path, &vcf2);

    int oneintwo = 0;
    int onenotintwo = 0;
    int twoinone = 0;
    int twonotinone = 0;

    typedef map<string, vector<int>>::iterator it;
    typedef vector<int>::iterator vit;

    for (it i = vcf1.begin(); i != vcf1.end(); i++) {
        for (vit v = i->second.begin(); v != i->second.end(); v++) {
            if (binary_search(vcf2[i->first].begin(), vcf2[i->first].end(), *v)) {
                oneintwo++;
            } else {
                onenotintwo++;
            }
        }
    }

    for (it i = vcf2.begin(); i != vcf2.end(); i++) {
        for (vit v = i->second.begin(); v != i->second.end(); v++) {
            if (binary_search(vcf1[i->first].begin(), vcf1[i->first].end(), *v)) {
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