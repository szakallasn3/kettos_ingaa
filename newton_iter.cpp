#include <iostream>
#include <math.h>

double sq(double x){
	return x*x;
}

double f(double x) {
	return cos(x) * exp(-sq(x));
}

template <typename myType>
myType trapezintegral(int n, myType a, myType b){
	const double w = (b-a)/n;

double t_i = 0;
for (int i = 0; i < n; i++){
	const double x1 = a + i*w;
	const double x2 = a + (i+1)*w;


	 t_i += 0.5 * (x2 - x1) * (f(x1) + f(x2));
}
	return t_i; 
}

int main(){
    int n1 = 10, n2 = 100, n3 = 1000, a = -1, b = 3;
    double tr_i1, tr_i2, tr_i3;
    tr_i1 = trapezintegral <double> (n1,a,b);
    tr_i2 = trapezintegral <double> (n2,a,b);
    tr_i3 = trapezintegral <double> (n3,a,b);
    std::cout.precision(16);
    std::cout << "Az integral erteke n = " << n1 << " eseten:\n"<< tr_i1 <<std::endl;
    std::cout << "Az integral erteke n = " << n2 << " eseten:\n"<< tr_i2 <<std::endl;
    std::cout << "Az integral erteke n = " << n3 << " eseten:\n"<< tr_i3 <<std::endl;
    return 0;
}
