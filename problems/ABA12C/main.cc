#include <algorithm>
#include <iostream>

int main(int argc, char* argv[]) {
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        int N;
        int K;
        std::cin >> N >> K;
        int price[K + 1];
        for (int i = 1; i <= K; i++) {
            std::cin >> price[i];
        }

        int min_cost[K + 1];
        for (int i = 1; i <= K; i++) {
            min_cost[i] = price[i];
        }

        for (int i = 1; i <= K; i++) {
            for (int j = 1; j < i; j++) {
                if (price[i - j] == -1 || min_cost[j] == -1) {
                    continue;
                }
                if (min_cost[i] == -1) {
                    min_cost[i] = min_cost[j] + price[i - j];
                } else {
                    min_cost[i] = std::min(min_cost[i], min_cost[j] + price[i - j]);
                }
            }
        }
        std::cout << ((K > 0) ? min_cost[K] : 0) << std::endl;
    }
    return 0;
}