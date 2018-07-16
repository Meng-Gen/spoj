#include <algorithm>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

#define MOD (1000000007)

typedef long long LL;

long long GetSum(LL a, LL b, LL c, LL n) {
    std::priority_queue< LL, std::vector<LL>, std::less<LL> > max_heap;
    std::priority_queue< LL, std::vector<LL>, std::greater<LL> > min_heap;

    LL sum = 1;
    LL m = 1;
    LL f;
    int max_heap_size;
    int min_heap_size;

    max_heap.push(1);

    for (int i = 2; i <= n; i++) {
        f = (a * m + b * i + c) % MOD;
        sum += f;

        if (f > m) {
            min_heap.push(f);
        } else {
            max_heap.push(f);
        }

        max_heap_size = max_heap.size();
        min_heap_size = min_heap.size();

        if (max_heap_size == min_heap_size + 2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            m = max_heap.top();
        } else if (max_heap_size + 2 == min_heap_size) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            m = max_heap.top();
        } else if (max_heap_size >= min_heap_size) {
            m = max_heap.top();
        } else {
            m = min_heap.top();
        }
    }

    return sum;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int testcases;
    LL a, b, c, n;

    std::cin >> testcases;
    while (testcases--) {
        std::cin >> a >> b >> c >> n;
        std::cout << GetSum(a, b, c, n) << '\n';
    }
    return 0;
}