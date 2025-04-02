#include "../headers/tokenizer.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

#ifdef _WIN32
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT
#endif

extern "C"{
    /*
    def splits(string: str, delimiters: list[str] = None, quotes: list[str] = None):
    if delimiters is None:
        delimiters = [' ', '\n']
    if quotes is None:
        quotes = []
    result = ['']
    current_quote = ''
    for char in str(string):
        if char in quotes:
            if current_quote == '':
                current_quote = char
                continue
            elif current_quote == char:
                current_quote = ''
                continue
        if current_quote == '':
            if char in delimiters:
                result.append('')
            else:
                result[-1] += char
        else:
            result[-1] += char
    return result
    */
    DLL_EXPORT std::vector<std::string> split (String text, String delimiters, String quotes){
        std::vector<std::string> result;
        std::string buffer;
        char current_quote = 0;
        foreach(c, std::string(text)){
            ifcontains(quotes, c){
                if(current_quote == 0){
                    current_quote = c;
                    continue;
                }
                else if(current_quote == c){
                    current_quote = 0;
                    continue;
                }
            }
            if(contains(delimiters, c) and current_quote == 0){
                result.push_back(buffer);
                //std::cout << "c " << buffer << std::endl;
                buffer = "";
            }
            else buffer += c;
        }
        return result;
    }

    DLL_EXPORT Tokens* tokenize (String text){
        Tokens* tokens = new Tokens();
        for(const auto& t : split(text)){
            char* ct = new char[t.size()+1];
            std::strcpy(ct, t.c_str());
            tokens->push_back(Token{ 
                .value=ct, // TODO: fix empty bytes
                .level=14, 
                .line=88
            });
        }
        for(auto t : *tokens){
            std::cout << "c " << t.value << std::endl;
        }
        return tokens;
    }

    DLL_EXPORT Token pop_token (Tokens* tokens){
        Token token = tokens->front();
        tokens->pop_back();
        return token;
    }

    DLL_EXPORT bool isempty (Tokens* tokens){
        return tokens->empty();
    }
}
