#include <algorithm>
#include <cstring>
#include <iostream>

#define MAX_LENGTH (200002)

long long a[MAX_LENGTH];
long long compressed[MAX_LENGTH];
long long tree[MAX_LENGTH];

long long Sum(int k) {
    long long s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & (-k);
    }
    return s;
}

void Add(int k, int x) {
    while (k <= MAX_LENGTH) {
        tree[k] += x;
        k += k & (-k);
    }
}

int main(int argc, char* argv[]) {
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        memset(tree, 0LL, sizeof(tree)); // initialize binary indexed tree

        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            compressed[i] = a[i];
        }
        std::sort(compressed, compressed + n); // compress array

        long long count = 0;
        for (int i = 0; i < n; i++) {
            int pos = std::lower_bound(compressed, compressed + n, a[i]) - compressed;
            count += Sum(n + 1) - Sum(pos + 1); // binary indexed tree is 1-based
            Add(pos + 1, 1);
        }

        std::cout << count << std::endl;
    }
    return 0;
}