#include <algorithm>
#include <cstring>
#include <iostream>

#define MAX_LENGTH (200002)

long long a[MAX_LENGTH];
long long compressed[MAX_LENGTH];

class BinaryIndexedTree {
private:
    long long tree[MAX_LENGTH];

public:
    BinaryIndexedTree() {
        memset(tree, 0LL, sizeof(tree));
    }

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
};

int main(int argc, char* argv[]) {
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            compressed[i] = a[i];
        }
        std::sort(compressed, compressed + n); // compress array

        BinaryIndexedTree tree;

        long long count = 0;
        for (int i = 0; i < n; i++) {
            int pos = std::lower_bound(compressed, compressed + n, a[i]) - compressed;
            count += tree.Sum(n + 1) - tree.Sum(pos + 1); // binary indexed tree is 1-based
            tree.Add(pos + 1, 1);
        }

        std::cout << count << std::endl;
    }
    return 0;
}