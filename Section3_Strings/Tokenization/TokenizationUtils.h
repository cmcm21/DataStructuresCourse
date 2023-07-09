#ifndef SECTION3_STRINGS_TOKENIZATION_UTILS_H
#define SECTION3_STRINGS_TOKENIZATION_UTILS_H

#include <vector>
#include <sstream>
#include <cstring>
#include <memory>


class TokenizationUtils
{
public:
    static std::vector<std::string> GetSeparateTokens_SS(std::string const &input, char separator);
    static std::vector<char *> GetSeparateTokens_STRTOK(char input[], char *separator);
    static std::vector<char *> GetSeparateTokens(char* input, char separator);

private:
    static char * GetFirstToken(char *input, char separator);
};


#endif
