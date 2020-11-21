// Title: coords.h
// Purpose: To complete problem 3 of EE262's exam (implementation file)
// Developer: Cameron Palmer, campalme@clarkson.edu
// Last Modified: November 5th, 2020

#include "coords.h"
#include <math.h>

using coords::rect_coords;
using coords::polar_coords;

const float PI = 3.14159265358979323846;

// All functions for rect_coords

rect_coords::rect_coords() {
    x_coord = 0;
    y_coord = 0;
    origin = true;
    tried_neg = false;
}

rect_coords::rect_coords(float x, float y) {

    if (x < 0 || y < 0){
        x_coord = 0;
        y_coord = 0;
        origin = true;
        tried_neg = true;
    }else {
        tried_neg = false;
        x_coord = x;
        y_coord = y;

        if (x == 0 && y == 0) {
            origin = true;
        } else {
            origin = false;
        }
    }
}

polar_coords rect_coords::toPolar() {
    polar_coords polar;

    polar.setCoords(sqrt(pow(x_coord, 2) + pow(y_coord, 2)), atan(y_coord/x_coord));

    return polar;
}

std::ostream& operator<<(std::ostream& out, rect_coords& coords){

    if(coords.checkTriedNeg()){
        out << "need xco >=0 and yco >=0 [will use Cartesian origin].";
        coords.triedNegFalse();
    }else {
        out << "[" << coords.getXCoord() << ", " << coords.getYCoord() << "]";
    }
    return out;
}

void rect_coords::setCoords(float x, float y) {
    x_coord = x;
    y_coord = y;
}

float rect_coords::getXCoord() {
    return x_coord;
}

float rect_coords::getYCoord() {
    return y_coord;
}

bool rect_coords::checkTriedNeg() {
    return tried_neg;
}

void rect_coords::triedNegFalse() {
    tried_neg = false;
}


// All functions for polar_coords

polar_coords::polar_coords() {
    r_coord = 0;
    theta_coord = PI/6;
    origin = true;
    tried_neg = false;
}

polar_coords::polar_coords(bool origininp, float r, float theta) {
    origin = origininp;
    if (r < 0 || theta < 0 || theta > PI/2){
        r_coord = 0;
        theta_coord = PI/6;
        tried_neg = true;
    }else {
        tried_neg = false;
        r_coord = r;
        theta_coord = theta;
    }
}

rect_coords polar_coords::toRectangular() {
    rect_coords rect;

    rect.setCoords(cos(r_coord), sin(r_coord));

    return rect;
}

std::ostream& operator<<(std::ostream& out, polar_coords& coords){
    if (coords.checkTriedNeg()){
        out << "need r>=0 and 0<=theta<=PI/2 [will use polar origin].";
        coords.triedNegFalse();
    }else {
        out << "(" << coords.getRCoord() << ", " << coords.getThetaCoord() << ")";
    }

    return out;
}

void polar_coords::setCoords(float r, float theta) {
    r_coord = r;
    theta_coord = theta;
}

float polar_coords::getRCoord() {
    return r_coord;
}

float polar_coords::getThetaCoord() {
    return theta_coord;
}

bool polar_coords::checkTriedNeg() {
    return tried_neg;
}

void polar_coords::triedNegFalse() {
    tried_neg = false;
}

void polar_coords::print(std::string string){
    std::cout << "Polar coordinates of " << string << "(" << r_coord << ", " << theta_coord << " rad)";
}

