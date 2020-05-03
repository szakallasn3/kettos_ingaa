#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include "kettos_inga.h"
#include <vector>
#include <math.h>
//const double Time = 22.8;

const double dt = 0.05; 
const double g = 9.81;
const double pi = 3.14;

template<typename F1>
auto Runge_kutta_step(double theta,double& h,double& t,F1 f){ /* 4ed rendu Runge-Kutta*/ 
    double k1 = f(t,theta);
    double k2 = f(t+h/2,theta+h*k1/2);
    double k3 = f(t+h/2,theta+h*k2/2);
    double k4 = f(t+h,theta+h*k3);
    
    return  h*(k1+2*k2+2*k3+k4)/6;
}

auto norm(double theta) { /* normalas annak érdekében, hogy a szögértékek 0 és 2pi közé essenek */
    if (theta > 2*pi) {
        while (theta > 2*pi) {
            theta -= 2*pi;
        }
    }
    if (theta < -2*pi) {
        while (theta < -2*pi) {
            theta += 2*pi;
        }
    }
    return theta;
}

auto Calculate_Runge_Kutta_step(double_pendulum& pendu,double& h,double& t){
    auto f1 =[&](double t,double theta){ /*Omega1 és omega2 értékeinek megadása*/
        return (-g*(2*pendu.m1() + pendu.m1()) * sin(theta) - pendu.m2()*g* sin(theta - 2*pendu.theta2()) - 
                2* sin (theta- 2*pendu.theta2())*pendu.m2()*(pendu.omega2()*pendu.omega2()*pendu.l2() + pendu.omega1()*pendu.omega1()*pendu.l1()*cos(theta - pendu.theta2())))
                /(pendu.l1()*(2*pendu.m1() + pendu.m2() - pendu.m2()*cos(2*theta-2*pendu.theta2())));
    };
    auto f2 = [&](double t,double theta){
        return (2*sin(pendu.theta1()-theta))*(pendu.omega1()*pendu.omega1()*pendu.l1()*pendu.M() + g*pendu.M()*cos(pendu.theta1()) +
                pendu.omega2()*pendu.omega2() * pendu.l2()*pendu.m2()*cos(pendu.theta1() - theta))/
                (pendu.l1()*(2*pendu.m1() + pendu.m2() - pendu.m2()*cos(2*pendu.theta1()-2*theta)));
    };

    auto dtheta1=Runge_kutta_step(pendu.theta1(),h,t,f1); /* dTheta és domega értékek kiszámítása*/ 
    auto dtheta2=Runge_kutta_step(pendu.theta2(),h,t,f2);

    auto domega1 = Runge_kutta_step(pendu.theta1(),h,t,[&](double t, double theta){return pendu.omega1();});
    auto domega2 = Runge_kutta_step(pendu.theta2(),h,t,[&](double t, double theta){return pendu.omega2();});

    pendu.upper.theta = norm(pendu.upper.theta + dtheta1); /* A már 0 és 2pi közé eső szögértékek hozzáadása*/
    pendu.lower.theta = norm(pendu.lower.theta + dtheta2);

    pendu.upper.omega += domega1; 
    pendu.lower.omega += domega2;
}

auto write_out(double_pendulum& pendu,std::ofstream& handler){ /* kiiras*/ 
    handler<<pendu.positions()<<std::endl;
}

auto step(double_pendulum& pendu, double& step_size,double time,std::ofstream& handler){
    Calculate_Runge_Kutta_step(pendu,step_size,time); 
    write_out(pendu,handler);
}

auto stepping(double_pendulum& pendu , double& time,double& step_size/* double dt */ ){ /* léptetés és az adatok kiírása fájlba */ 
    std::ofstream handler("datas.txt");
    for(double current_time = 0.0; current_time<time;current_time+=dt){
        step(pendu,step_size,current_time,handler);
    }
    handler.close();
}

int main() {
    double step_size = 0.05; /* h a Runge-Kuttaban */
    double time = 15.0; /* meddig tartson a léptetés*/

    double_pendulum pendul = {{0.5,0.1,1,1},{1,0.2,0.4,0.25}}; /* kezdeti értékek megadása: theta, omega, l, m  mindkét ingarészre*/
    stepping(pendul,time,step_size);

    return 0;
}