#include <ios>
#include <iostream>

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    long long n;
    long long k;
    std::cin >> n >> k;
    long long count = 0;
    long long a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        if (a % k == 0) {
            count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}