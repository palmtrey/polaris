// Title: pmul.cpp
// Description & Purpose: This is a program to automate the multiplication of polynomials
// Author: Cameron Palmer, campalme@clarkson.edu
// Last Modified: September 23rd, 2020

#include <iostream>
#include <vector>

// Function defs
void ip_multiply(); // Multiplies two polynomials and prints out the result to the screen
void getUserInput(); // Gets information from the user
void printPolynomial(std::vector <int> vec); // Prints a polynomial 
void printPolynomialTraditional(std::vector <int> vec); // Prints a polynomial in a traditional math form

// Define variables for polynomial-related info, and vectors to contain the polynomials themselves
int p1Degree = 0;
int p2Degree = 0;

std::vector <int> p1(0); // The first polynomial from user input
std::vector <int> p2(0); // The second polynomial from user input
std::vector <int> p3(0); // The multiplied polynomial


int main(){

	
	getUserInput();
	ip_multiply();
	printPolynomialTraditional(p3);
	
	


	return 0;

}

void ip_multiply(){

	int firstVal;
	int secondVal;
	int multVal;
	int degreeOfMultVal;
	int tempValFromPoly;

	for (int i = 0; i <= p1Degree; i++){
		firstVal = p1[i];
		for (int j = 0; j <= p2Degree; j++){
			degreeOfMultVal = i + j;
			tempValFromPoly = p3[degreeOfMultVal];
			secondVal = p2[j];
			multVal = firstVal * secondVal;
			p3[degreeOfMultVal] = p3[degreeOfMultVal] + multVal;
			
		}

	}
	

	return;
}

void getUserInput(){
	std::cout << "Enter the degree of p1: \n> ";
	std::cin >> p1Degree;

	for (int i = 0; i <= p1Degree; i++){
		int tempVal = 0;
		std::cout << "[p1] coefficient of x^" << i << ":\n> ";
		std::cin >> tempVal;
		
		p1.push_back(tempVal);

	}

	std::cout << std::endl;

	std::cout << "Enter the degree of p2: \n> ";
	std::cin >> p2Degree;

	for (int i = 0; i <= p2Degree; i++){
		int tempVal = 0;
		std::cout << "[p2] coefficient of x^" << i << ":\n> ";
		std::cin >> tempVal;
		
		p2.push_back(tempVal);

	}


	// Init p3 with the correct amount of zeros
	for (int i = 1; i < p1.size() + p2.size(); i++){
		p3.push_back(0);
	}
	return;


}

void printPolynomial(std::vector <int> vec){
	std::cout << " Product -- [";
	for(int i = 0; i <= vec.size(); i++){
		

		if (i == vec.size()){
			std::cout << vec[i];
		}else{
			std::cout << vec[i] << ", ";
		}
	}
	std::cout << "]";
	return;
}

void printPolynomialTraditional(std::vector <int> vec){
	for(int i = 0; i <= vec.size(); i++){
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
			}
		}
	}
	return;
}