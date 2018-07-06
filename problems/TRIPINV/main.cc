#include <cstring>
#include <ios>
#include <iostream>
#include <vector>

#define MAX_LENGTH (100002)

int n;
std::vector<long long> first_tree(MAX_LENGTH, 0);
std::vector<long long> second_tree(MAX_LENGTH, 0);

long long Query(std::vector<long long>& tree, int k) {
    long long s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & (-k);
    }
    return s;
}

void Update(std::vector<long long>& tree, int k, long long v) {
    while (k <= n) {
        tree[k] += v;
        k += k & (-k);
    }
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;
    long long count = 0;
    int a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        Update(first_tree, a, 1);
        long long inversion_count = Query(first_tree, n) - Query(first_tree, a);
        Update(second_tree, a, inversion_count);
        count += Query(second_tree, n) - Query(second_tree, a);
    }
    std::cout << count << '\n';
    return 0;
}