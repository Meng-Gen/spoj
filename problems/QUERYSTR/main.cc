#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> ZAlgorithm(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    int x = 0;
    int y = 0;
    for (int k = 1; k < n; k++) {
        if (y < k) {
            x = k;
            y = k;
            int j = x;
            while (j < n && s[j] == s[j - x]) {
                j++;
            }
            y = j - 1;
            z[k] = y - x + 1;
        } else if (k + z[k - x] <= y) {
            z[k] = z[k - x];
        } else {
            x = k;
            int j = y + 1;
            while (j < n && s[j] == s[j - x]) {
                j++;
            }
            y = j - 1;
            z[k] = y - x + 1;
        }
    }
    z[0] = n;
    return z;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int testcases;
    int n;
    int num_queries;
    int x;

    std::cin >> testcases;
    while (testcases--) {
        std::string s;
        std::cin >> s;
        std::reverse(s.begin(), s.end());
        std::vector<int> z = ZAlgorithm(s);
        n = s.length();
        std::cin >> num_queries;
        while (num_queries--) {
            std::cin >> x;
            std::cout << z[n - x] << '\n';
        }
    }
    return 0;
}