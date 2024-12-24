#include <iostream>

double sum(double A) {
    double numerator = 2.0, denumerator = 3.0;
    double decimal = numerator / denumerator;
    double sum = 0.0;
    while (decimal >= A) {
        sum += decimal;
        numerator += 1.0;
        denumerator += 4.0;
        decimal = numerator / denumerator;
    }
    return sum;
}

int main() {
    double A;
    std::cout << "Input A in format x.xxx:\n";
    std::cin >> A;
    std::cout << "Current sum is; " << sum(A) << std::endl;
    return 0;
}
