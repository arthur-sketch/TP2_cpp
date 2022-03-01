#include <iostream>
#include <math.h>
#pragma once

template<typename TYPE>
struct bezier {


    TYPE P[4];

    public :

    bezier() 
        :P{(TYPE) 0.0,(TYPE) 0.0,(TYPE) 0.0,(TYPE) 0.0 }
    {};
    bezier(TYPE P0,TYPE P1,TYPE P2,TYPE P3) 
        :P{ P0,P1,P2,P3 }
    {}

    TYPE coeff(int k) const {
        return P[k];
    }
    
    TYPE& coeff(int k) {
        return P[k];
    }

    TYPE operator() (TYPE s) const {
        return pow(1 - s, 3) * (*this).coeff(0) + 3 * pow(1 - s, 2) * s * (*this).coeff(1) + 3 * (1 - s) * pow(s, 2) * (*this).coeff(2) + pow(s, 3) * (*this).coeff(3);
    }


};

template<typename TYPE>
std::ostream& operator<<(std::ostream& s, bezier<TYPE> const & v) {
    s << "(1-s)^3*" << v.coeff(0) << "+3*(1-s)^2*s*" << v.coeff(1) << "+3*(1-s)*s^2*" << v.coeff(2) << "+s^3*" << v.coeff(3);
    return s;
}
