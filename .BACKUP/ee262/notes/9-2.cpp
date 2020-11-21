#include<iostream>
#include<string>

int main(){

	typedef double* DoublePtr;
	
	int amount = 0;

	std::cout << "Enter an array size:" << std::endl << "> ";
	std::cin >> amount;

	DoublePtr d = new double[amount];

	d[amount-1] = amount;

	d[1] = 2;
	
	std::cout << *(d + 1) << std::endl;	

		

	delete [] d;

	return 0;
}
