#include <iostream>
#include <string>
#include <vector>

int Count(std::vector<char>& stack) {
    int count = 0;
    for (int i = 0; i < stack.size(); i += 2) {
        count += (stack[i] == stack[i + 1]) ? 1 : 2;
    }
    return count;
}

int main(int argc, char* argv[]) {
    int testcases = 0;
    while (++testcases) {
        std::string content;
        std::cin >> content;

        if (content.length() > 0 && content[0] == '-') {
            break;
        }

        std::vector<char> stack;
        for (int i = 0; i < content.length(); i++) {
            char c = content[i];
            if (c == '{') {
                stack.push_back(c);
            } else if (c == '}') {
                if (stack.size() > 0 && stack.back() == '{') {
                    stack.pop_back();
                } else {
                    stack.push_back(c);
                }
            }
        }
        std::cout << testcases << ". " << Count(stack) << std::endl;
    }
    return 0;
}