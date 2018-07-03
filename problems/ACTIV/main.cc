#include <algorithm>
#include <iostream>
#include <utility>

#define MAX_CLASS_COUNT (100001)
#define MOD (100000000)

int n;
std::pair<long long, long long> classes[MAX_CLASS_COUNT];
long long count[MAX_CLASS_COUNT] = {0};

long long GetNonEmptyCount() {
    count[0] = 1;

    for (int i = 1; i <= n; i++) {
        std::pair<long long, long long> value;
        value.first = classes[i].second;
        value.second = classes[i].second;

        int pos = std::upper_bound(classes, classes + n + 1, value) - classes - 1;
        count[i] = count[i - 1] + count[pos];
        if (count[i] > MOD) {
            count[i] -= MOD;
        }
    }
    return count[n] - 1;
}

int main(int argc, char* argv[]) {
    while (true) {
        std::cin >> n;
        if (n == -1) {
            break;
        }
        classes[0].first = -1;
        classes[0].second = -1;
        for (int i = 1; i <= n; i++) {
            std::cin >> classes[i].second >> classes[i].first;
        }
        std::sort(classes, classes + n + 1);
        printf("%0.8lld\n", GetNonEmptyCount());
    }
    return 0;
}