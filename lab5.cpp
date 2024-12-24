#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
    Point() {
        x = 0.0;
        y = 0.0;
    }
    Point(double newX, double newY) {
        x = newX;
        y = newY;
    }
};

double module(const Point &first, const Point &second) {
    return sqrt(std::pow(first.x - second.x, 2) + std::pow(first.y - second.y, 2));
}

void input(Point &first, Point &second, Point &third) {
    std::cout << "Input first point in format: x y\n";
    std::cin >> first.x >> first.y;
    std::cout << "Input second point in format: x y\n";
    std::cin >> second.x >> second.y;
    std::cout << "Input third point in format: x y\n";
    std::cin >> third.x >> third.y;
}

double calculate(const Point &first, const Point &second, const Point &third) {
    double a = module(first, second);
    double b = module(third, second);
    double c = module(first, third);
    double halfPerimeter = (a + b + c) / 2;
    return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
}

int main() {
    Point a, b, c;
    input(a, b, c);
    std::cout << calculate(a, b, c);
    return 0;
}
