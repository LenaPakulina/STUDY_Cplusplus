#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

void sumNum() {
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;
    std::cout << num1 + num2;
}

void minLengthStr() {
    std::string str;
    std::cin >> str;
    std::string temp;
    for (int i = 0; i < 2; i++) {
        std::cin >> temp;
        if (temp < str) {
            str = temp;
        }
    }
    std::cout << str;
}


void discriminant() {
    double a = 0, b = 0, c = 0;
    double d = 0;
    std::cin >> a >> b >> c;

    if (a != 0) {
        d = pow(b,2) - 4*a*c;
        if (d < 0) {
            return;
        }
        double x1 = ((-1)*b + sqrt(d))/(2*a);
        double x2 = ((-1)*b - sqrt(d))/(2*a);
        if (x1 != x2) {
            std::cout << x1 << ' ' << x2;
        } else {
            std::cout << x1;
        }
    } else {
        if (b != 0) {
            std::cout << ((-1)*c/b);
        }
    }
}

void division() {
    int a, b;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << "Impossible";
    } else {
        std::cout << a/b;
    }
}

void discontPrice() {
    double N, A, B, X, Y;
    std::cin >> N >> A >> B >> X >> Y;
    if (N > A && N <= B) {
        N = N*(1 - X/100);
    }
    if (N > B) {
        N = N*(1 - Y/100);
    }
    std::cout << N;
}

void coutEvenNum() {
    int A, B;
    std::cin >> A >> B;
    for (int i = A; i <= B; i++) {
        if (i % 2 == 0) {
            std::cout << i << ' ';
        }
    }
}

void secondOccurrence() {
    std::string str;
    std::cin >> str;
    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'f') {
            count++;
        }
        if (count == 2) {
            std::cout << i;
            return;
        }
    }

    if (count == 0) {
        std::cout << -2;
    } else {
        std::cout << -1;
    }
}

void greatestCommonDivisor() {
    int A, B;
    std::cin >> A >> B;
    while (A > 0 && B > 0) {
        if (A > B) {
            A = A % B;
        } else {
            B = B % A;
        }
    }
    std::cout << A + B;
}

void convertToBinaryForms() {
    int a = 0;
    std::cin >> a;
    std::vector<int> retVect;
    while (a != 1) {
        retVect.push_back(a % 2);
        a = a / 2;
    }
    retVect.push_back(1);
    std::reverse(retVect.begin(), retVect.end());
    for (int i = 0; i < retVect.size(); i++) {
        std::cout << retVect[i];
    }
}

int main() {
    convertToBinaryForms();
    // greatestCommonDivisor();
    // secondOccurrence();
    // coutEvenNum();
    // discontPrice();
    // division();
    // discriminant();
    // minLengthStr();
    // sumNum();
    return 0;
}