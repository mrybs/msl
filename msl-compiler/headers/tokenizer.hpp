#include <vector>
#include <string>

#define foreach(x, y) for(auto x : y)
#define contains(x, y) std::string(x).find(y) != std::string::npos
#define ifcontains(x, y) if(std::string(x).find(y) != std::string::npos)
typedef const char* String;
typedef std::vector<String> Strings;

extern "C" {
    struct Token{
        char* value;
        uint32_t level;
        uint32_t line; 
    };
    typedef std::vector<Token> Tokens;

    std::vector<std::string> split(String text, String delimiters = " \n", String quotes = "");
    Token pop_token(Tokens* tokens);
    bool isempty(Tokens* tokens);
    Tokens* tokenize(const char* text);
}