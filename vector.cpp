#include <iostream>
#include <math.h>
#include "vector2.h"

int main()
{

    vector <double> v = {2,5};
    vector <double> u = {4,3};
    double p = 3.0;
    std::cout <<"Az első vektor: u = " << u<< std::endl;
    std::cout <<"A második vektor: v = " << v << std::endl;
 
    std::cout << " Az u vektor hossza:"<< length(u) <<"\n";
    std::cout << " Az u vektor hosszának négyzete:"<< sqlength(u) <<"\n";
    std::cout <<"A két vektor skalárszorzata: "<< dot(u,v) << "\n";
    
    vector <double> w = u; w += v;
    std::cout << "A két vektor összege: " << w << std::endl;
    vector <double> w1 = u; w1 -= v;
    std::cout << "A két vektor különbsége: " << w1 << std::endl;
    vector <double> w2 = u; w2 *=p;
    std:: cout << "Az u vektor szorozva p = "<< p << " skalárral: " << w2 <<std:: endl;
    vector <double> w3 = v; w3 /=3;
    std:: cout << "A v vektor osztva p skalárral: " << w3 <<std:: endl;
    std::cout <<"Az u vektor normált alakja:"<< normalize(u) << "\n";
}
