// Title: analyzeGrades.cpp
// Purpose: To complete problem 1 of the EE262 Fall 2020 exam
// Developer: Cameron Palmer, campalme@clarkson.edu
// Last Modified: November 5th, 2020

#include<iostream>
#include<stdlib.h>
// Defining the type that will be used to store grades
typedef double* varArray;

// Computes and prints the highest grade attained, the lowest grade attained, and the average of the grades
// Inputs: An int representing the number of classes given by the user, a varArray containing the grades for each class
void computeStats(int, varArray);

int main(){
    int numCourses = 0; // Number of courses
    varArray grades; // A variable array holding grades for each course

    // Ask the user for the number of courses
    std::cout << "Enter number of courses:" << std::endl << "> ";
    std::cin >> numCourses;

    if (numCourses <= 0){
        std::cout << "Cannot have negative or zero courses. Will exit." << std::endl;
        exit(1);
    }

    // Set the size of grades to be the same as the number of courses given
    grades = new double[numCourses];

    // Get a grade for each class from the user; check if the grade is in the proper range
    for (int i = 0; i < numCourses; i++){
        std::cout << "Enter grade (0-100) for course #" << i + 1<< ":" << std::endl << "> ";
        std::cin >> grades[i];

        if (grades[i] > 100 || grades[i] < 0){
            std::cout << "Grade out of range. Will quit." << std::endl;
            exit(2);
        }
    }

    // Call computeStats to get stats for the grades
    std::cout << "Calling computeStats for analysis..." << std::endl;
    computeStats(numCourses, grades);

    // Delete grades to return it to the freestore
    delete [] grades;

    return 0;
}

void computeStats(int nc, varArray gradesList){
    // Calculate minimum grade


    double minGrade = 100;

    for (int i = 0; i < nc; i++){
        if (gradesList[i] < minGrade){
            minGrade = gradesList[i];
        }
    }

    double maxGrade = 0;
    for (int i = 0; i < nc; i++){
        if (gradesList[i] > maxGrade){
            maxGrade = gradesList[i];
        }
    }

    double avgGrade = 0;
    double total = 0;

    for(int i = 0; i < nc; i++){
        total += gradesList[i];
    }

    avgGrade = total/nc;

    std::cout << "Minimum grade: " << minGrade << std::endl;
    std::cout << "Maximum grade: " << maxGrade << std::endl;
    std::cout << "Average grade: " << avgGrade << std::endl;
}
