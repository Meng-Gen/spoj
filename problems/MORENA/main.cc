#include <iostream>
#include <vector>

#define UP (1)
#define DOWN (-1)
#define FLAT (0)

int GetTrend(long long first, long long second) {
    if (first < second) {
        return UP;
    } else if (first > second) {
        return DOWN;
    } else {
        return FLAT;
    }
}

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;
    long long heights[n];
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    int max_length = 1;
    int last_max_trend = FLAT;
    for (int i = 1; i < n; i++) {
        int trend = GetTrend(heights[i - 1], heights[i]);
        if ((last_max_trend == UP && trend == DOWN)
                || (last_max_trend == DOWN && trend == UP) 
                || (last_max_trend == FLAT && trend != FLAT)
        ) {
            max_length++;
            last_max_trend = trend;
        }
    }
    std::cout << max_length << std::endl;
    return 0;
}