#include <iostream>
#include <string>
#include <vector>

#define BUFFER_SIZE 15

int isKeyword(const std::string& buffer, const std::vector<std::string>& keywords) {
    for (const auto& keyword : keywords) {
        if (keyword == buffer) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char ch;
    std::string buffer;
    const char operators[] = "+-*/%=";
    const char separators[] = "(){}[],";
    
    std::vector<std::string> keywords;
    std::cout << "Enter keywords (one per line, type 'done' when finished):" << std::endl;
    while (true) {
        std::string keyword;
        std::cin >> keyword;
        if (keyword == "done") {
            break;
        }
        keywords.push_back(keyword);
    }

    std::cout << "Enter the input to analyze" << std::endl;

    while (std::cin.get(ch)) {
        for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); ++i) {
            if (ch == operators[i]) {
                std::cout << " OPERATOR:     " << ch << std::endl;
            } else if (ch == separators[i]) {
                std::cout << " SEPARATOR:    " << ch << std::endl;
            }
        }

        if (isalnum(ch)) {
            buffer += ch;
        } else if ((ch == ' ' || ch == '\n') && (!buffer.empty())) {
            if (isKeyword(buffer, keywords) == 1) {
                std::cout << " KEYWORD:      " << buffer << std::endl;
            } else {
                std::cout << " IDENTIFIER:   " << buffer << std::endl;
            }
            buffer.clear();
        }
    }

    return 0;
}