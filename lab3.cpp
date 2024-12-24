#include <iostream>

static int N;

void foo(int **massive) {
    int stepLength;
    for (int i = 1; i < N + 1; ++i) {
        stepLength = 2 * i;
        massive[i - 1] = new int[stepLength];
        for (int j = 0; j < stepLength; ++j) {
            massive[i - 1][j] = j + 1;
        }
    }
}

void print() {
    int **massive = new int*[N];
    foo(massive);
    int stepLength;
    for (int i = 1; i < N + 1; ++i) {
        stepLength = i * 2;
        for (int j = 0; j < stepLength; ++j) {
            std::cout << massive[i - 1][j] << "  ";
        }
        std::cout << '\n';
    }
}

int main() {
    std::cout << "Input N:\n";
    std::cin >> N;
    if (N > 0) {
        print();
    } else {
        std::cout << "No-no-no...\n";
    }
    return 0;
}
