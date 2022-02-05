#include <iostream>

int main() {
    int temp_counter = 50;
    int sum = 0;
    while (temp_counter <= 100) {
        sum += temp_counter;
        temp_counter++;
    }

    std::cerr << sum << std::endl;
    std::clog << sum << std::endl;
    std::cout << sum << std::endl;
    return 0;
}