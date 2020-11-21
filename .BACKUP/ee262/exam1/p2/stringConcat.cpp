// Title: stringConcat.cpp
// Purpose: To complete problem 2 of EE262's exam
// Developer: Cameron Palmer, campalme@clarkson.edu
// Last Modified: November 5th, 2020

#include <iostream>
#include <cstring>

// Takes in two cstrings and returns their concatenation
// Inputs: Two cstrings to concatenate
// Output: The concatenated cstring
char* my_strcat(const char*, const char*);


int main(){

    using namespace std;

    // Driver code has been copy-pasted here

    cout<<my_strcat((char*)"test2", (char*)" greetings")<<endl;

    cout<<my_strcat("test1", " hello.")<<endl;
    cout<<my_strcat("now", " this.")<<endl<<endl;

    char v1[] = "the time ";
    char v2[] = "has come ";
    char v3[] = "for all good men to come to the aid ... of the party. ";
    char v4[] = "End of filler text.";

    char* r1 = my_strcat(v1, v2);
    char* r2 = my_strcat(r1, v3);
    char* r3 = my_strcat(r2, v4);
    cout<<"r3: "<<r3<<endl<<endl;



    char t1[] = "Woodrow ";
    char t2[] = "Wilson ";
    char t3[] = "listed Fourteen Points.";
    char* lst14 = my_strcat(t1, my_strcat(t2, t3));
    cout<<"lst14: "<<lst14<<endl;

    return 0;
    return 0;
}


char* my_strcat(const char* s1, const char* s2){

    char* string1 = (char*)s1;
    char* string2 = (char*)s2;

    int len1 = strlen(string1);
    int len2 = strlen(string2);

    for(int i = 0; i < len2; i++){
        string1[len1] = string2[i];
        len1 = len1 + 1;
    }

    string1[len1] = '\0';

    return string1;

}