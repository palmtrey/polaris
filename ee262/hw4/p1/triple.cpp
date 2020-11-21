// Title: Triple.cpp
// Purpose: To provide an implementation file for triple.h
// Developers: Cameron Palmer, Shawn Boyd
// Last Modified: November 21st, 2020

#include "triple.h"

// First constructor w/o name
template <typename T>
simSequence::Triple<T>::Triple(T first, T second, T third) {
    Triple<T>::first = first;
    Triple<T>::second = second;
    Triple<T>::third = third;
    Triple<T>::name = "unnamed";
}

// Second constructor w/ name
template <typename T>
simSequence::Triple<T>::Triple(T first, T second, T third, string name) {
    Triple<T>::first = first;
    Triple<T>::second = second;
    Triple<T>::third = third;
    Triple<T>::name = name;
}

// Get the first element of the triple
template <typename T>
T simSequence::Triple<T>::getFirst() {
    return first;
}

// Get the second element of the triple
template <typename T>
T simSequence::Triple<T>::getSecond() {
    return second;
}

// Get the third element of the triple
template <typename T>
T simSequence::Triple<T>::getThird() {
    return third;
}

// Print out the triple
template <typename T>
void simSequence::Triple<T>::print() {
    std::cout << name << ": (" << first << ", " << second << ", " << third << ")" << std::endl;
}

// Explicit Instantiations
template class simSequence::Triple<long>;
template class simSequence::Triple<char>;
template class simSequence::Triple<double>;
template class simSequence::Triple<std::string>;
template class simSequence::Triple<int>;