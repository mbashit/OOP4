#include <iostream>
#include <stdexcept>

class Pair {
public:
    double first;
    double second;

public:
    Pair(double a, double b) : first(a), second(b) {}

    // Method for addition
    Pair add(const Pair& other) {
        double result_first = first + other.first;
        double result_second = second + other.second;
        return Pair(result_first, result_second);
    }
    
    // Operator overloading for addition
    Pair operator+(const Pair& other) {
        return add(other);
    }

    // Method for multiplication
    Pair multiply(const Pair& other) {
        double result_first = first * other.first;
        double result_second = second * other.second;
        return Pair(result_first, result_second);
    }

    // Operator overloading for multiplication
    Pair operator*(const Pair& other) {
        return multiply(other);
    }

    // Method for division
    Pair divide(const Pair& other) {
        double denominator = other.first * other.first + other.second * other.second;
        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
        }

        double result_first = (first * other.first / second * other.second) / denominator;
        double result_second = (second * other.first / first * other.second) / denominator;
        return Pair(result_first, result_second);
    }

    // Operator overloading for division
    Pair operator/(const Pair& other) {
        return divide(other);
    }

    // Method for subtraction
    Pair subtract(const Pair& other) {
        double result_first = first - other.first;
        double result_second = second - other.second;
        return Pair(result_first, result_second);
    }

    // Operator overloading for subtraction
    Pair operator-(const Pair& other) {
        return subtract(other);
    }

    void display() {
        std::cout << "(" << first << ", " << second << ")";
    }

    double getFirst() { return first; }

    double getSecond() { return second; }
};


class Complex : public Pair {
public:
    Complex(double real, double imag) : Pair(real, imag) {}

    // Method for adding a Complex object to a Pair object
    Complex add(const Complex& other) {
        Pair temp = Pair::add(other); // Use the Pair::add method to add Pair objects
        //double real = temp.first;   // Access 'first' directly
        //double imag = temp.second;  // Access 'second' directly
        return Complex(temp.getFirst(), temp.getSecond());
    }

    Complex subtract(const Complex& other) {
        Pair temp = Pair::subtract(other); // Use the Pair::add method to add Pair objects
        //double real = temp.first;   // Access 'first' directly
        //double imag = temp.second;  // Access 'second' directly
        return Complex(temp.getFirst(), temp.getSecond());
    }

    // Method for multiplication of complex numbers using the provided formula
    Complex multiply(const Complex& other) {
        double real = first;
        double imag = second;
        double other_real = other.first;
        double other_imag = other.second;

        double result_real = (real * other_real) - (imag * other_imag);
        double result_imag = (imag * other_real) + (real * other_imag);

        return Complex(result_real, result_imag);
    }

    // Method for division of complex numbers using the provided formula
    Complex divide(const Complex& other) {
        double real = first;
        double imag = second;
        double other_real = other.first;
        double other_imag = other.second;

        double denominator = (other_real * other_real) + (other_imag * other_imag);
        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
        }

        double result_real = ((real * other_real) + (imag * other_imag)) / denominator;
        double result_imag = ((imag * other_real) - (real * other_imag)) / denominator;

        return Complex(result_real, result_imag);
    }
    void display() {
        std::cout << first << "+i  " << second;
    }
};

int main() {
    Pair p1(3, -4);
    Pair p2(2, 5);

    std::cout << "Pair 1: ";
    p1.display();
    std::cout << std::endl;

    std::cout << "Pair 2: ";
    p2.display();
    std::cout << std::endl;

    Pair multiplication_result = p1.multiply(p2);
    Pair addition_result = p1 + p2;
    Pair subtraction_result = p1 - p2;
    Pair division_result = p1.divide(p2);

    std::cout << "Multiplication result: ";
    multiplication_result.display();
    std::cout << std::endl;

    std::cout << "Addition result: ";
    addition_result.display();
    std::cout << std::endl;

    std::cout << "Subtraction result: ";
    subtraction_result.display();
    std::cout << std::endl;

    std::cout << "Division result: ";
    division_result.display();
    std::cout << std::endl;

    Complex c1(3, -4);
    Complex c2(2, 5);

    std::cout << "Complex 1 (Real, Imaginary): ";
    c1.display();
    std::cout << std::endl;

    std::cout << "Complex 2 (Real, Imaginary): ";
    c2.display();
    std::cout << std::endl;

    Complex complex_multiplication_result = c1.multiply(c2);
    Complex complex_division_result = c1.divide(c2);
    Complex complex_adding_result = c1.add(c2);
    Complex complex_subtracting_result = c1.subtract(c2);

    std::cout << "Complex Multiplication result (Real, Imaginary): ";
    complex_multiplication_result.display();
    std::cout << std::endl;

    std::cout << "Complex Division result (Real, Imaginary): ";
    complex_division_result.display();
    std::cout << std::endl;

    std::cout << "Complex adding result (Real, Imaginary): ";
    complex_adding_result.display();
    std::cout << std::endl;

    std::cout << "Complex subtracting result (Real, Imaginary): ";
    complex_subtracting_result.display();
    std::cout << std::endl;

    return 0;
}