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
    if (b == c) return 0;
    return ((b * b + c * c - a * a) / (2 * b * c));
    }

double arccos(double x) {
    //if (x < -1.0 || x > 1.0) return NAN;
    //if (x == 1.0) return 0.0;
    //if (x == -1.0) return 3.1415926535;           у нас существует треугольник
    if (x == 0) return 3.1415926535 / 2;

    // ряд Тейлора для arccos через arcsin
    // arccos(x) = π/2 - arcsin(x)
    // arcsin(x) = x + (1/2)*(x³/3) + (1*3)/(2*4)*(x⁵/5) + ...

    double result = x;
    double term = x;
    double x2 = x * x;

    for (int n = 1; n < 20; n++) {
        term *= x2 * (2 * n - 1) * (2 * n - 1) / (4 * n * n + 2 * n);
        result += term;
        if (std::abs(term) < 1e-10) break;
    }

    return 3.1415926535 / 2 - result;
}

double med(double a, double b, double c) {
    return cor(2 * b * b + 2 * c * c - a * a) / 2;
}

double bis(double c, double b, double a) {
    return cor(a * b * (a + b + c) * (a + b - c)) / (a + b);
}

int main() {
    setlocale(LC_ALL, "RU");
    double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите координаты вершин треугольника:\nx1, y1: ";
    std::cin >> x1 >> y1;
    std::cout << "x2, y2: ";
    std::cin >> x2 >> y2;
    std::cout << "x3, y3: ";
    std::cin >> x3 >> y3;

    // 1. Длина сторон
    double AB = length(x1, y1, x2, y2);
    double BC = length(x2, y2, x3, y3);
    double CA = length(x3, y3, x1, y1);
    
    // 8. Периметр
    double P = AB + BC + CA;
    
    // 8. Площадь треугольника
    double S1 = area1(AB, BC, CA, P);
    
    //double S2 = area1(BC, h_AB);
    //std::cout << "Площадь треугольника: " << S2 << std::endl;

    //double S3 = area3(x1, y1, x2, y2, x3, y3);
    //std::cout << "Площадь треугольника: " << S3 << std::endl;

    // 6. Радиусы окружностей
    double r_in = inradius(S1, P);
    double r_out = outradius(AB, BC, CA, S1);
    
    // 5. Углы в радианах и градусах
    double angleA = arccos(my_cos(BC, AB, CA));
    double angleB = arccos(my_cos(CA, AB, BC));
    double angleC = arccos(my_cos(AB, BC, CA));

    // 2. Длина высот
    double h_AB = (2 * S1) / AB;
    double h_BC = (2 * S1) / BC;
    double h_CA = (2 * S1) / CA;

    // 3. Длина медиан
    double m_A = med(BC, AB, CA);
    double m_B = med(CA, AB, BC);
    double m_C = med(AB, BC, CA);

    // 4. Длина биссектрис
    double bis_A = bis(BC, AB, CA);
    double bis_B = bis(CA, AB, BC);
    double bis_C = bis(AB, BC, CA);

    // 7. Площадь окружностей
    double sB = 3.1415926535 * r_out * r_out;
    double sM = 3.1415926535 * r_in * r_in;

    // 7. Длина окружностей
    double dB = 3.1415926535 * r_out * 2;
    double dM = 3.1415926535 * r_in * 2;

    std::cout << "Длина сторон:\nAB: " << AB << "\nBC: " << BC << "\nCA: " << CA << std::endl;
    std::cout << "Длина высот:\nК AB: " << h_AB << "\nК BC: " << h_BC << "\nК CA: " << h_CA << std::endl;
    std::cout << "Длина медиан:\nК AB: " << m_A << "\nК BC: " << m_B << "\nК CA: " << m_C << std::endl;
    std::cout << "Длина биссетрис:\nК AB: " << bis_A << "\nК BC: " << bis_B << "\nК CA: " << bis_C << std::endl;
    std::cout << "Углы треугольника (в радианах):\nA: " << angleA << "\nB: " << angleB << "\nC: " << angleC << std::endl;
    std::cout << "Углы треугольника (в градусах):\nA: " << angleA * (180 / 3.1415926535) << "\nB: " << angleB * (180 / 3.1415926535) << "\nC: " << angleC * (180 / 3.1415926535) << std::endl;
    std::cout << "Радиус вписанной окружности: " << r_in << std::endl;
    std::cout << "Радиус описанной окружности: " << r_out << std::endl;
    std::cout << "Площадь описанной окружности: " << sB << "\nПлощадь вписанной окружности: " << sM << std::endl;
    std::cout << "Длина описанной окружности: " << dB << "\nДлина вписанной окружности: " << dM << std::endl;
    std::cout << "Площадь треугольника: " << S1 << std::endl;
    std::cout << "Периметр треугольника: " << P;

    return 0;
}