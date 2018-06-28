#include <iostream>

long long GetCount(std::string& encoded) {
    long long prev = 1LL;
    long long curr = 1LL;
    for (int i = 1; i < encoded.length(); i++) {
        long long next = 0LL;
        int prev_digit = encoded[i - 1] - '0';
        int curr_digit = encoded[i] - '0';
        if (prev_digit == 1 || ((prev_digit == 2) && (curr_digit <= 6))) {
            next += prev;
        }
        if (curr_digit != 0) {
            next += curr;
        }
        prev = curr;
        curr = next;
    }
    return curr;
}

int main(int argc, char* argv[]) {
    std::string encoded;
    while (true) {
        std::cin >> encoded;
        if (encoded == "0") {
            break;
        } else {
            std::cout << GetCount(encoded) << std::endl;
        }
    }
    return 0;
}