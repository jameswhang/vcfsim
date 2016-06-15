//
// Created by jameswhang on 6/15/16.
//
#include "vcfparser.h"

void vcfparser::readfile(string filepath, map<string, vector<int>> * vcfmap) {
    std::ifstream file(filepath);
    std::string   line;
    int lcount = 0;

    while(std::getline(file, line))
    {
        if (lcount < 111) {
            lcount += 1;
            continue;
        }

        std::stringstream   lstream(line);
        string data;
        string chromosome;
        int position;

        // If you have truly tab delimited data use getline() with third parameter.
        // If your data is just white space separated data
        // then the operator >> will do (it reads a space separated word into a string).
        std::getline(lstream, data, '\t');  // read up-to the first tab (discard tab).

        // Read the integers using the operator >>
        lstream >> position;
        chromosome = data;

        if (vcfmap->find(chromosome) != vcfmap->end()) {
            (*vcfmap)[chromosome].push_back(position);
        } else {
            vector<int> v;
            v.push_back(position);
            (*vcfmap)[chromosome] = v;
        }
    }
}
