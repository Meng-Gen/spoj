#include <algorithm>
#include <ios>
#include <iostream>

#define MAX_LENGTH (10001)

long long first_sequence[MAX_LENGTH];
long long second_sequence[MAX_LENGTH];

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    //std::cin.tie(0);

    int first_length;
    int second_length;
    while (true) {
        std::cin >> first_length;
        if (first_length == 0) {
            break;
        }
        for (int i = 0; i < first_length; i++) {
            std::cin >> first_sequence[i];
        }

        std::cin >> second_length;
        for (int i = 0; i < second_length; i++) {
            std::cin >> second_sequence[i];
        }

        /*
        for (int i = 0; i < first_length; i++) {
            std::cout << first_sequence[i] << " ";
        }
        std::cout << '\n';
        for (int i = 0; i < second_length; i++) {
            std::cout << second_sequence[i] << " ";
        }
        std::cout << '\n';
        */

        long long max_sum = 0;
        long long partial_sum_at_first = 0;
        long long partial_sum_at_second = 0;
        int first_pos = 0;
        int second_pos = 0;
        while (first_pos < first_length && second_pos < second_length) {
            long long first = first_sequence[first_pos];
            long long second = second_sequence[second_pos];
            if (first == second) {
                max_sum += std::max(partial_sum_at_first, partial_sum_at_second) + first;
                partial_sum_at_first = 0;
                partial_sum_at_second = 0;
                first_pos++;
                second_pos++;
            } else if (first > second) {
                partial_sum_at_second += second;
                second_pos++;
            } else {
                partial_sum_at_first += first;
                first_pos++;
            }
        }
        for (; first_pos < first_length; first_pos++) {
            partial_sum_at_first += first_sequence[first_pos];
        }
        for (; second_pos < second_length; second_pos++) {
            partial_sum_at_second += second_sequence[second_pos];
        }
        max_sum += std::max(partial_sum_at_first, partial_sum_at_second);
        std::cout << max_sum << '\n';
    }
    return 0;
}