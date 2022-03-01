#include "bezier.hpp"




bezier::bezier()
    :P{0.0f,0.0f,0.0f,0.0f}
    {}

bezier::bezier(float P0,float P1,float P2,float P3)
    :P{P0,P1,P2,P3}
    {}

float bezier::coeff(int k) const {
    return P[k];
}

float& bezier::coeff(int k) {
    return P[k];
}

float bezier::operator() (float s) const {
    return pow(1-s,3)*(*this).coeff(0)+3*pow(1-s,2)*s*(*this).coeff(1)+3*(1-s)*pow(s,2)*(*this).coeff(2)+pow(s,3)*(*this).coeff(3);
}

std::ostream& operator<<(std::ostream& s,bezier const & v) {
    s<<"(1-s)^3*"<<v.coeff(0)<<"+3*(1-s)^2*s*"<<v.coeff(1)<<"+3*(1-s)*s^2*"<<v.coeff(2)<<"+s^3*"<<v.coeff(3);
    return s;
}