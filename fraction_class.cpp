#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    Fraction operator+(const Fraction &other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        return Fraction(new_num, new_denom);
    }

    Fraction operator-(const Fraction &other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_denom = denominator * other.denominator;
        return Fraction(new_num, new_denom);
    }

    Fraction operator*(const Fraction &other) const {
        int new_num = numerator * other.numerator;
        int new_denom = denominator * other.denominator;
        return Fraction(new_num, new_denom);
    }

    Fraction operator/(const Fraction &other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        int new_num = numerator * other.denominator;
        int new_denom = denominator * other.numerator;
        return Fraction(new_num, new_denom);
    }

    void display() const {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {
    try {
        Fraction a(1, 2);
        Fraction b(3, 4);

        Fraction sum = a + b;
        Fraction difference = a - b;
        Fraction product = a * b;
        Fraction quotient = a / b;

        std::cout << "a: ";
        a.display();
        std::cout << std::endl;

        std::cout << "b: ";
        b.display();
        std::cout << std::endl;

        std::cout << "a + b = ";
        sum.display();
        std::cout << std::endl;

        std::cout << "a - b = ";
        difference.display();
        std::cout << std::endl;

        std::cout << "a * b = ";
        product.display();
        std::cout << std::endl;

        std::cout << "a / b = ";
        quotient.display();
        std::cout << std::endl;
    } catch (const std::invalid_argument &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
