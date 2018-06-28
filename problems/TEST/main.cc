#include <iostream>

int main(int argc, char* argv[]) {
    int a;
    while (true) {
        std::cin >> a;
        if (a == 42) {
            break;
        } else {
            std::cout << a << std::endl;
        }
    }
    return 0;
}