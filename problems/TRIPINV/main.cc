#include <cstring>
#include <iostream>
#include <vector>

#define MAX_LENGTH (100002)

int n;
std::vector<long long> first_tree(MAX_LENGTH, 0);
std::vector<long long> second_tree(MAX_LENGTH, 0);

void Update(std::vector<long long>& tree, int k, long long v) {
    while (k > 0) {
        tree[k] += v;
        k -= k & (-k);
    }
}

long long Query(std::vector<long long>& tree, int k) {
    long long sum = 0;
    while (k <= n) {
        sum += tree[k];
        k += k & (-k);
    }
    return sum;
}

int main(int argc, char* argv[]) {
    std::cin >> n;
    long long count = 0;
    int a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        Update(first_tree, a, 1);
        long long inversion_count = Query(first_tree, a + 1);
        Update(second_tree, a, inversion_count);
        count += Query(second_tree, a + 1);
    }
    std::cout << count << std::endl;
    return 0;
}