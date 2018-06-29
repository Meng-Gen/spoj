#include <algorithm>
#include <iostream>
#include <map>

std::map<long long, long long> cache;

long long Get(long long n) {
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }
    cache[n] = std::max(n, Get(n / 2) + Get(n / 3) + Get(n / 4));
    return cache[n];
}

int main(int argc, char* argv[]) {
    cache[0] = 0;
    cache[1] = 1;

    long long n;
    while (std::cin >> n) {
        std::cout << Get(n) << std::endl;
    }
    return 0;
}