// Title: coords.h
// Purpose: To complete problem 3 of EE262's exam (interface file)
// Developer: Cameron Palmer, campalme@clarkson.edu
// Last Modified: November 5th, 2020

#ifndef COORDS_H
#define COORDS_H

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include<string>


namespace coords {
    class rect_coords;

    class polar_coords;

    class rect_coords {
    public:
        rect_coords();

        rect_coords(float x, float y);

        polar_coords toPolar();

        friend std::ostream& operator<<(std::ostream& out, rect_coords& coords);

        void setCoords(float x, float y);

        float getXCoord();

        float getYCoord();

        bool checkTriedNeg();

        void triedNegFalse();

    private:
        float x_coord;
        float y_coord;
        bool origin; // Set to true if the coordinates represent the origin
        bool tried_neg; // Set to true if the user tried to enter values outside the first quadrant
    };


    class polar_coords {
    public:
        polar_coords();

        polar_coords(bool origininp, float r, float theta);

        rect_coords toRectangular();

        friend std::ostream& operator<<(std::ostream& out, polar_coords& coords);

        void setCoords(float r, float theta);

        float getRCoord();

        float getThetaCoord();

        bool checkTriedNeg();

        void triedNegFalse();

        void print(std::string string);

    private:
        float r_coord;
        float theta_coord;
        bool origin; // Set to true if the coordinates represent the origin
        bool tried_neg; // Set to true if the user tried to enter values outside the first quadrant
     };
};

#endif //COORDS_H
