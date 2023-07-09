#ifndef SECTION3_STRINGS_UTILS_H
#define SECTION3_STRINGS_UTILS_H
#include <string>
#include <vector>

class Utils
{
public:
    static std::vector<int> SearchAllOccurrences(std::string bigString, std::string smallString);
    static std::vector<int> SearchAllOccurrences(std::string bigString, char character);
    static std::string Space20(std::string source, std::string word, char character);
    static void PrintVector(const std::vector<int> &arr);

};


#endif
