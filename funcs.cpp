//https://contest.yandex.ru/contest/27794/problems/A/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::vector<long int> a,b;
    int aLen, bLen;

    input >> aLen;
    a.resize(aLen);
    std::copy_n(std::istream_iterator<long int>(input),aLen,a.begin());
    input >> bLen;
    b.resize(bLen);
    std::copy_n(std::istream_iterator<long int>(input),bLen,b.begin());

    long int aClosest = *a.begin(), bClosest = *b.begin();
    long int diff = std::abs(aClosest - bClosest), aiDiff, curDiff;

    auto bStart = b.begin();

    for(auto & ai : a){
        aiDiff = std::abs(ai - *bStart);
        for(auto bi = bStart+1; bi != b.end(); ++bi){
            curDiff = std::abs(*bi - ai);
            if(curDiff>=aiDiff)
                break;
            aiDiff = curDiff;
            bStart = bi;
        }

        if(aiDiff >= diff) continue;

        diff = aiDiff;
        aClosest = ai;
        bClosest = *bStart;
        if(diff == 0)
            break;
    }

    output << aClosest << ' ' << bClosest;
}
