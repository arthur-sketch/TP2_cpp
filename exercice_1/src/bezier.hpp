#include <iostream>
#include <math.h>
#pragma once


struct bezier {


    float P[4];

    public :

    bezier();
    bezier(float P0,float P1,float P2,float P3);

    float coeff(int k) const;
    float& coeff(int k);

    float operator() (float s) const;


};


std::ostream& operator<<(std::ostream& s, bezier const & v);
