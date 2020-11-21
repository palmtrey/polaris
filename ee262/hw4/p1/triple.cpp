// Title: Triple.cpp
// Purpose: To provide an implementation file for triple.h
// Developers: Cameron Palmer, Shawn Boyd
// Last Modified: November 21st, 2020

#include "triple.h"

using namespace simSequence;

template <typename T>
Triple<T>::Triple(T first, T second, T third) {
    Triple<T>::first = first;
    Triple<T>::second = second;
    Triple<T>::third = third;
    Triple<T>::name = "unnamed";
}

template <typename T>
Triple<T>::Triple(T first, T second, T third, string name) {
    Triple<T>::first = first;
    Triple<T>::second = second;
    Triple<T>::third = third;
    Triple<T>::name = name;
}

template <typename T>
T Triple<T>::getFirst() {
    return first;
}

template <typename T>
T Triple<T>::getSecond() {
    return second;
}

template <typename T>
T Triple<T>::getThird() {
    return third;
}

template <typename T>
void Triple<T>::print() {
    std::cout << name << ": (" << first << ", " << second << ", " << third << ")" << std::endl;
}
