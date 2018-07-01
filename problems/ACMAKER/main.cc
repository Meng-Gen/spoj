// 2014-04-27
// modified 2014-10-07
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
    for (;;) {
        int n; cin >> n; if (n == 0) return 0;
        set<string> insignificant;
        for (int i = 0; i < n; i++) {
            string s; cin >> s; insignificant.insert(s);
        }
        for (;;) {
            string acro; cin >> acro; cin.ignore();
            string phrase; getline(cin, phrase);
            if (phrase == "CASE") break;
            istringstream iss(phrase);
            vector<string> words;
            for (;;) {
                string word; iss >> word;
                if (word == "") break;
                if (insignificant.find(word) == insignificant.end()) {
                    words.push_back(word);
                }
            }
            // dp[i][j] is the number of ways to use the first i words and the
            // first j letters of the acronym
            int dp[151][151]; memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            int dp2[151][151];
            for (int i = 0; i < words.size(); i++) {
                for (int j = 0; j < acro.length(); j++) {
                    // How many letters of this word do we want to use?
                    int mx = min(acro.length() - j, words[i].length());
                    for (int k = 0; k <= words[i].length(); k++) {
                        dp2[k][0] = 1;
                    }
                    for (int k = 1; k <= mx; k++) {
                        dp2[0][k] = 0;
                    }
                    for (int k = 0; k < words[i].length(); k++) {
                        for (int m = 0; m < mx; m++) {
                            dp2[k+1][m+1] = dp2[k][m+1];
                            if (words[i][k] == tolower(acro[j+m])) {
                                dp2[k+1][m+1] += dp2[k][m];
                            }
                        }
                    }
                    for (int k = 1; k <= mx; k++) {
                        dp[i+1][j+k] += dp[i][j] * dp2[words[i].length()][k];
                    }
                }
            }
            if (dp[words.size()][acro.length()] == 0) {
                cout << acro << " is not a valid abbreviation" << endl;
            } else {
                cout << acro << " can be formed in "
                     << dp[words.size()][acro.length()] << " ways" << endl;
            }
        }
    }
}

/*
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

int Get(const std::string acronym, const std::vector<std::string>& words) {
    // dp[i][j] is the number of ways to use the first i words and the
    // first j letters of the acronym
    int dp[151][151]; //memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int dp2[151][151];
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < acronym.length(); j++) {
            // How many letters of this word do we want to use?
            int mx = std::min(acronym.length() - j, words[i].length());
            for (int k = 0; k <= words[i].length(); k++) {
                dp2[k][0] = 1;
            }
            for (int k = 1; k <= mx; k++) {
                dp2[0][k] = 0;
            }
            for (int k = 0; k < words[i].length(); k++) {
                for (int m = 0; m < mx; m++) {
                    dp2[k+1][m+1] = dp2[k][m+1];
                    if (words[i][k] == tolower(acronym[j+m])) {
                        dp2[k+1][m+1] += dp2[k][m];
                    }
                }
            }
            for (int k = 1; k <= mx; k++) {
                dp[i+1][j+k] += dp[i][j] * dp2[words[i].length()][k];
            }
        }
    }
    return dp[words.size()][acronym.length()];


//    return words.size();
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
            int ways_count = Get(acronym, significant_words);
            if (ways_count == 0) {
                std::cout << acronym << " is not a valid abbreviation" << std::endl;
            } else {
                std::cout << acronym << " can be formed in " << ways_count << " ways" << std::endl;
            }
        } 
    }
    return 0;
}
*/