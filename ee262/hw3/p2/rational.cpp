// Title: rational.cpp
// Purpose: To create a class to represent rational numbers using the form: numerator / denominator
// Developer: Cameron Palmer, campalme@clarkson.edu
// Last Modified: October 21st, 2020

#include <iostream>
#include <fstream>


class rational {

public:
    // Creates an instance of the class using just one number (the denominator will be 1)
    rational(int number);

    // Creates an instance of the class using two numbers, numerator and denominatort
    rational(int num, int denom);

    // Gets input values for a rational number from the specified input
    void input(std::istream& x);

    // Outputs stored values of the rational number to the specified output
    void output(std::ostream& y, std::string label);

    // Adds a rational number to the object of which the function is called and returns the result
    rational add(rational x);

    // Subtracts a rational number from the object of which the function is called and returns the result
    rational sub(rational x);

    // Multiplies a rational number with the object of which the function is called and returns the result
    rational mul(rational x);

    // Divides a the object of which the function is called by a rational number x
    rational div(rational x);

    // Determines if the object of which the function is called is less than a provided rational number x
    bool less(rational x);

    // Returns the negative of the object of which the function is called
    rational neg();

private:
    int numerator;
    int denominator;

    // Outputs an error if the denominator is zero
    void denominatorIsZero();

    // Returns the greatest common denominator of two unsigned ints
    unsigned int gcd(unsigned int n1 , unsigned int n2);
};

rational::rational(int number){
    numerator = number;
    denominator = 1;
}

rational::rational(int num, int denom) {
    if (denom == 0){
        denominatorIsZero();
    }

    numerator = num;
    denominator = denom;
}

void rational::input(std::istream& x){
    std::cout << "Enter numerator: ";
    x >> numerator;
    std::cout << "Enter denominator: ";
    x >> denominator;

    if (denominator == 0){
        denominatorIsZero();
    }
}

void rational::output(std::ostream& y, std::string label){

    // If the denominator is negative, move the negative sign to the numerator
    if (denominator < 0){
        numerator = numerator * -1;
        denominator = denominator * -1;
    }

    y << label << ": " << numerator << "/" << denominator << std::endl;
}

rational rational::add(rational x) {
    int a = numerator;
    int b = denominator;
    int c = x.numerator;
    int d = x.denominator;

    return rational((a * d + b * c), (b * d));
}

rational rational::sub(rational x) {
    int a = numerator;
    int b = denominator;
    int c = x.numerator;
    int d = x.denominator;

    return rational((a * d - b * c), (b * d));
}

rational rational::mul(rational x){
    int a = numerator;
    int b = denominator;
    int c = x.numerator;
    int d = x.denominator;

    return rational((a * c), (b*d));
}

rational rational::div(rational x){
    int a = numerator;
    int b = denominator;
    int c = x.numerator;
    int d = x.denominator;

    return rational((a * d), (b * c));
}

bool rational::less(rational x) {
    int a = numerator;
    int b = denominator;
    int c = x.numerator;
    int d = x.denominator;

    return (a * d) < (c * b);
}

rational rational::neg() {
    return rational(numerator * -1, denominator);
}

void rational::denominatorIsZero() {
    std::cerr << "Denominator can't be zero";
    exit(-1);
}


unsigned int rational::gcd (unsigned int n1 , unsigned int n2) {
    unsigned int tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}