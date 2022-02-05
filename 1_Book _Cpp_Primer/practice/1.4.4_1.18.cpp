#include <iostream>

int main() {
    int value = 0, currValue = 0;
    if (std::cin >> value) {
        int count = 1;
        while (std::cin >> currValue) {
            if (value == currValue) {
                count++;
            } else {
                std::cout << "Count num " << value << " is " << count << std::endl;
                value = currValue;
                count = 1;
            }
        }
        std::cout << "Count num " << value << " is " << count << std::endl;
    }

    return 0;
}