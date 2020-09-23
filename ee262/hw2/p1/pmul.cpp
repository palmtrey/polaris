// Title: pmul.cpp
// Description & Purpose: This is a program to automate the multiplication of polynomials
// Author: Cameron Palmer, campalme@clarkson.edu
// Last Modified: September 23rd, 2020

#include <iostream>
#include <vector>

// Function defs
void ip_multiply(); // Multiplies two polynomials and prints out the result to the screen
void getUserInput(); // Gets information from the user
void printPolynomial(std::vector <int> vec); // Prints a polynomial as a list of numbers 
void printPolynomialTraditional(std::vector <int> vec); // Prints a polynomial in traditional math form

// Define variables for polynomial-related info, and vectors to contain the polynomials themselves
int p1Degree = 0;
int p2Degree = 0;

std::vector <int> p1(0); // The first polynomial from user input
std::vector <int> p2(0); // The second polynomial from user input
std::vector <int> p3(0); // The multiplied polynomial


int main(){
	getUserInput(); // Get the polynomials from the user
	ip_multiply(); // Multiply the polynomials

	// Print the result in both forms
	std::cout << "Product -- "; 
	printPolynomialTraditional(p3);
	printPolynomial(p3);
	
	return 0;

}


// Multiples the two polynomials together and stores the result in p3
void ip_multiply(){

	int firstVal; // The first value to multiply
	int secondVal; // The second value to multiply
	int multVal; // The multipled value
	int degreeOfMultVal; // The degree of the multipled value (ex. degree of 3 translates to multVal*x^3)

	// Multiply out the polynomials, taking the each term from the first polynomial and multiplying it by each term of the second,
	// then moving to the second term from the first polynomial and so on
	for (int i = 0; i <= p1Degree; i++){
		firstVal = p1[i];
		for (int j = 0; j <= p2Degree; j++){
			degreeOfMultVal = i + j;
			secondVal = p2[j];
			multVal = firstVal * secondVal;
			p3[degreeOfMultVal] = p3[degreeOfMultVal] + multVal;
			
		}

	}
	

	return;
}


// Takes in the user's choice of two polynomials
void getUserInput(){

	// Start by getting the first polynomial from the user
	std::cout << "Enter the degree of p1: \n> ";
	std::cin >> p1Degree;

	// Get all coefficients of the first polynomial
	for (int i = 0; i <= p1Degree; i++){
		int tempVal = 0;
		std::cout << "[p1] coefficient of x^" << i << ":\n> ";
		std::cin >> tempVal;
		
		p1.push_back(tempVal);

	}
	std::cout << std::endl;
	printPolynomialTraditional(p1);
	std::cout << std::endl;


	std::cout << std::endl; // Provide a space in the input to make the input stream a bit clearer


	// Get the second polynomial from the user
	std::cout << "Enter the degree of p2: \n> ";
	std::cin >> p2Degree;

	// Get all coefficients for the second polynomial
	for (int i = 0; i <= p2Degree; i++){
		int tempVal = 0;
		std::cout << "[p2] coefficient of x^" << i << ":\n> ";
		std::cin >> tempVal;
		
		p2.push_back(tempVal);

	}

	std::cout << std::endl;
	printPolynomialTraditional(p2);
	std::cout << std::endl;


	// Init p3 with the correct amount of zeros
	for (int i = 1; i < p1.size() + p2.size(); i++){
		p3.push_back(0);
	}
	return;


}


void printPolynomial(std::vector <int> vec){
	std::cout << "[";
	for(int i = 0; i <= vec.size() - 1; i++){
		if (i != vec.size()-1){
			std::cout << vec[i] << ", ";
		}else{
			std::cout << vec[i];
		}
	}
	std::cout << "]" << std::endl;
	return;
}


void printPolynomialTraditional(std::vector <int> vec){
	for(int i = 0; i <= vec.size() - 1; i++){
		if (vec[i] != 0){
			switch(i){
				case 0:
					std::cout << vec[i];
					break;
				case 1:
					std::cout << vec[i] << "x";
					break;
				default:
					std::cout << vec[i] << "x^" << i;		
			}

			if (i != vec.size()-1){
				std::cout << " + ";
			}else{
				std::cout << std::endl;
			}
		}
	}
	return;
}
