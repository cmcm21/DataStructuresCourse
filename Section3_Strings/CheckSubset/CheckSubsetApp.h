//
// Created by layca on 11/19/2022.
//

#ifndef SECTION3_STRINGS_CHECKSUBSETAPP_H
#define SECTION3_STRINGS_CHECKSUBSETAPP_H
#include <string>
#include <map>


class CheckSubsetApp
{
public:
    bool isSubset;
    std::string source;
    std::string target;
    CheckSubsetApp(): isSubset(false){}
    void Run(bool performance = false);
private:
    void Resolve();

    void ResolvePerformance();
    void GetInput();
    std::map<char,int> GetSourceMap();
};


#endif //SECTION3_STRINGS_CHECKSUBSETAPP_H
