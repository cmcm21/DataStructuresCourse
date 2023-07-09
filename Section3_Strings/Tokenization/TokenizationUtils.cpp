#include "TokenizationUtils.h"

std::vector<std::string> TokenizationUtils::GetSeparateTokens_SS(std::string const &input, char separator)
{
    std::vector<std::string> tokens;
    std::stringstream stringS(input);

    std::string token;
    while(std::getline(stringS,token,separator))
        tokens.push_back(token);

    return tokens;
}

std::vector<char *> TokenizationUtils::GetSeparateTokens_STRTOK(char *input, char *separator) {
    std::vector<char *> tokens;

    char *token = std::strtok(input, separator);
    while(token != nullptr)
    {
        tokens.push_back(token);
        token = std::strtok(nullptr, separator);
    }
    return tokens;
}

std::vector<char *> TokenizationUtils::GetSeparateTokens(char *input, char separator) {
    std::vector<char *> tokens;
    char *token = GetFirstToken(input,separator);

    while(token != nullptr)
    {
        tokens.push_back(token);
        token = GetFirstToken(nullptr,separator);
    }
    return tokens;
}

char *TokenizationUtils::GetFirstToken(char *str, char separator)
{
    static char * input = nullptr;

    if(str != nullptr)
        input = str;
    if(input == nullptr)
        return nullptr;

    char *token = new char[strlen(input) + 1];

    size_t i = 0;
    for(; input[i] != '\0'; i++ )
    {
        if(input[i] != separator)
            token[i] = input[i];
        else
        {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }
    token[i] = '\0';
    input = nullptr;
    return token;
}
