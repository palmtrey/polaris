// Title: rational.cpp
// Purpose: To create a class to represent rational numbers using the form: numerator / denominator
// Developer: Cameron Palmer, campalme@clarkson.edu
// Last Modified: October 21st, 2020

#include <iostream>
#include <fstream>
#include <stdlib.h>

class rational {

public:
    // Creates an object with no values
    rational();

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
    unsigned int gcd(int n1 , int n2);
};

rational::rational(){
    numerator = 0;
    denominator = 1;
}

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

    // If the rational number can be reduced, reduce it

    int gcdNum = gcd(numerator, denominator);

    if (gcdNum != 1 || gcdNum != -1){
        numerator = numerator/gcdNum;
        denominator = denominator/gcdNum;
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
    int tempNum = -numerator;
    return rational(tempNum, denominator);
}

void rational::denominatorIsZero() {
    std::cerr << "Denominator can't be zero";
    exit(-1);
}


unsigned int rational::gcd (int n1 , int n2) {
    unsigned int tmp;

    // Turn negatives positive
    if (n1 < 0){
        n1 = -n1;
    }
    if(n2 < 0){
        n2 = -n2;
    }

    // Compute gcd
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}



int main(){

    using namespace std;

    rational r1(10, 3);
    rational r2(8, -2);

    r1.output(cout, "r1");
    r2.output(cout, "r2");

    rational r3 = r2.neg();
    r3.output(cout, "r3");

    rational r4 = r1.neg();
    r4.output(cout, "r4");

    rational r6 = r3.add(r1);
    r6.output(cout, "r6");

    cout<<endl;
    ifstream in1;
    in1.open("inp1.txt");
    rational r5;
    cout<<"r5 will get input from ifstream (connected to inp1.txt):"<<endl;
    r5.input(in1);
    in1.close();
    r5.output(cout, "r5");
    cout<<endl;

    rational r7 = r3.sub(r1);
    r7.output(cout, "r7");

    rational r8 = r6.mul(r7);
    r8.output(cout, "r8");

    rational r9 = r8.div(r5);
    r9.output(cout, "r9");

    cout<<"r9 < r1: "<<r9.less(r1)<<endl;
    cout<<"r4 < r5: "<<r4.less(r5)<<endl;
    cout<<"r6 < r8: "<<r6.less(r8)<<endl;
    cout<<"r1 < r3: "<<r1.less(r3)<<endl;

    cout<<endl;
    rational y1(70);
    y1.output(cout, "y1");

    cout<<endl;
    rational y2;
    y2.output(cout, "y2");

    cout<<"y2 will now get input from cin: "<<endl;
    y2.input(cin);
    //enter: 34/-6 (user input)
    y2.output(cout, "y2");


    cout<<endl;
    ofstream ofs;
    ofs.open("log1.txt", ofstream::out); //ofstream::app
    r1.output(ofs, "r1");
    r2.output(ofs, "r2");
    r3.output(ofs, "r3");
    r4.output(ofs, "r4");
    r5.output(ofs, "r5");
    r6.output(ofs, "r6");
    r7.output(ofs, "r7");
    r8.output(ofs, "r8");
    r9.output(ofs, "r9");
    y1.output(ofs, "y1");
    y2.output(ofs, "y2");

    ofs.close();

    rational r10(18, 0);
    rational r11(12, 4);

    return 0;
}




