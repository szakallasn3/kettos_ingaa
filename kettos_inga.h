#include <iostream>
#include <fstream>
#include <string>

struct pendulum{
    double theta;
    double omega;
    double l;
    double m;
};

struct double_pendulum
{
    pendulum upper;
    pendulum lower;
    
    std::string positions(){
        return std::to_string(upper.theta) + " " +std::to_string(lower.theta);
    }
    double M(){
        return upper.m + lower.m;
    }
    double m1(){
        return upper.m;
    }

    double m2(){
        return lower.m;
    }

    double l1(){
        return upper.l;
    }

    double l2(){
        return lower.l;
    }

    double omega1(){
        return upper.omega;
    }

    double omega2(){
        return lower.omega;
    }

    double theta1(){
        return upper.theta;
    }
    
    double theta2(){
        return lower.theta;
    }

    double d(){
        return upper.theta - lower.theta;
    }

};