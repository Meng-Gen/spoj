#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> Split(const std::string& content) {
    std::vector<std::string> tokens;
    std::istringstream content_stream(content);
    for (std::string token; content_stream >> token; ) {
        tokens.push_back(token);
    }
    return tokens;
}

int GetCount(const std::string& acronym, const std::vector<std::string>& words) {
    // count[i][j] is the number of ways to use the first i words and the
    // first j letters of the acronym.
    int count[151][151] = {0};
    count[0][0] = 1;

    int count_in_word[151][151];
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < acronym.length(); j++) {
            // How many letters of this word do we want to use?
            int max_in_word = std::min(acronym.length() - j, words[i].length());
            for (int k = 0; k <= words[i].length(); k++) {
                count_in_word[k][0] = 1;
            }
            for (int k = 1; k <= max_in_word; k++) {
                count_in_word[0][k] = 0;
            }
            for (int k = 0; k < words[i].length(); k++) {
                for (int m = 0; m < max_in_word; m++) {
                    count_in_word[k+1][m+1] = count_in_word[k][m+1];
                    if (words[i][k] == tolower(acronym[j+m])) {
                        count_in_word[k+1][m+1] += count_in_word[k][m];
                    }
                }
            }
            for (int k = 1; k <= max_in_word; k++) {
                count[i+1][j+k] += count[i][j] * count_in_word[words[i].length()][k];
            }
        }
    }
    return count[words.size()][acronym.length()];
}

int main(int argc, char* argv[]) {
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::set<std::string> insignificant_words;
        std::string word;
        for (int i = 0; i < n; i++) {
            std::cin >> word;
            insignificant_words.insert(word);
        }
        std::cin.ignore();
        while (true) {
            std::string line;
            getline(std::cin, line);
            if (line == "LAST CASE") {
                break;
            }
            std::vector<std::string> all_words = Split(line);
            std::string acronym = all_words[0];
            std::vector<std::string> significant_words;
            for (int i = 1; i < all_words.size(); i++) {
                if (insignificant_words.find(all_words[i]) == insignificant_words.end()) {
                    significant_words.push_back(all_words[i]);
                }
            }
            int count = GetCount(acronym, significant_words);
            if (count == 0) {
                std::cout << acronym << " is not a valid abbreviation" << std::endl;
            } else {
                std::cout << acronym << " can be formed in " << count << " ways" << std::endl;
            }
        } 
    }
    return 0;
}