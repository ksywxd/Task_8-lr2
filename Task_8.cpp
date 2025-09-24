#include <iostream>

double cor(double a) {
    double low = 0, high = a, mid;
    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2;
        if (mid * mid == a) return mid;
        else if (mid * mid < a) low = mid;
        else if (mid * mid > a) high = mid;
    }
    return mid;
}

double length(double x1, double y1, double x2, double y2) {
    return cor((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double area1(double a, double b, double c, double P) {
    double  p = P / 2;
    return cor(p * (p - a) * (p - b) * (p - c));
}

double area2(double a, double h) {
    return 0.5 * a * h;
}

double area3(double x1, double y1, double x2, double y2, double x3, double y3) {
    double S = 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (S < 0) S = -S;
    return S;
}

double inradius(double S, double P) {
    return S / (P / 2);
}

double outradius(double a, double b, double c, double S) {
    return (a * b * c) / (4 * S);
}
double my_cos(double a, double b, double c) {
    return cor((b * b + c * c - a * a) / (2 * b * c));
    }

double angle(double a, double b, double c) {
    return acos((b * b + c * c - a * a) / (2 * b * c));
}

int main() {
    setlocale(LC_ALL, "RU");
    double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите координаты вершин треугольника (x1, y1, x2, y2, x3, y3): ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // 1. Длина сторон
    double AB = length(x1, y1, x2, y2);
    double BC = length(x2, y2, x3, y3);
    double CA = length(x3, y3, x1, y1);
    std::cout << "Длина сторон:\nAB: " << AB << "\nBC: " << BC << "\nCA: " << CA << std::endl;

    // 2. Периметр
    double P = AB + BC + CA;
    std::cout << "Периметр треугольника: " << P << std::endl;

    // 3. Площадь треугольника
    double S1 = area1(AB, BC, CA, P);
    std::cout << "Площадь треугольника: " << S1 << std::endl;

    //double S2 = area1(BC, h_AB);
    //std::cout << "Площадь треугольника: " << S2 << std::endl;

    //double S3 = area3(x1, y1, x2, y2, x3, y3);
    //std::cout << "Площадь треугольника: " << S3 << std::endl;

    // 4. Радиусы окружностей
    double r_in = inradius(S1, P);
    double r_out = outradius(AB, BC, CA, S1);
    std::cout << "Радиус вписанной окружности: " << r_in << std::endl;
    std::cout << "Радиус описанной окружности: " << r_out << std::endl;

    // 5. Углы в радианах и градусах
    double angleA = angle(BC, AB, CA);
    double angleB = angle(CA, BC, AB);
    double angleC = angle(AB, CA, BC);

    std::cout << "Углы треугольника (в радианах):\nA: " << angleA << "\nB: " << angleB << "\nC: " << angleC << std::endl;
    std::cout << "Углы треугольника (в градусах):\nA: " << angleA * (180 / 3.1415926535) << "\nB: " << angleB * (180 / 3.1415926535) << "\nC: " << angleC * (180 / 3.1415926535) << std::endl;

    return 0;
}