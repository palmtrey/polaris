#include <iostream>

int main(){
	
	int userNum = 0;

	std::cout << "Enter an integer more than 1:" << std::endl;
	std::cout << ">";
	
	std::cin >> userNum;

	int counter = 2;
	
	std::cout << "Factors of " << userNum << ": 1";
	while(counter <= userNum/2){
		if(userNum % counter == 0){
			std::cout << ", " << counter;
		}
		counter++;
	}

	std::cout << std::endl;
	return 0;
}
