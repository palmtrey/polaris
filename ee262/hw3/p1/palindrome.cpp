// Title: palindrome.cpp
// Purpose: To determine if a given command line argument cstring is a palidrome or not (white spaces are significant)
// Developer: Cameron Palmer, campalme@clarkson.edu
// Last Modified: October 20, 2020

#include <iostream>
#include <cstring>

// Checks whether or not a provided c_string is a palindrome or not
bool isPalindrome(const char*);

int main(int argc, char* argv[]){

    if (argc == 2){
        bool palindrome = isPalindrome(argv[1]);

        if (palindrome == true) {
            std::cout << argv[1] << " is a palindrome." << std::endl;
        }else{
            std::cout << argv[1] << " is not a palindrome." << std::endl;
        }

    }else{
        std::cout << "usage: palindrome str_to_test" << std::endl;
    }

    return 0;
}





bool isPalindrome(const char* test){

    for (int i = 0, j = strlen(test) - 1; i < j; i++, j--){
        if (test[i] != test[j]){
            return false;
        }
    }

    return true;
}