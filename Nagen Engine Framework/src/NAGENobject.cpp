//
//  NAGENobject.cpp
//  Nagen Engine Framework
//
//  Created by Farmat on 2023-11-19.
//

#include <cmath>
#include <iostream>

#include "../include/NAGENobject.hpp"
 #include "../include/globalConsts.h"

void NAGENobject::moveStraight(double length) {
    
    double xAdditive = length * sin(thetaAngle) * cos(phiAngle);
    double yAdditive = length * sin(thetaAngle) * sin (phiAngle);
    double zAdditive = length * cos(thetaAngle);
    
    
    if (xAdditive < 1e-9 and xAdditive > -1e-9) {
        xAdditive = 0;
    }
    if (yAdditive < 1e-9 and yAdditive > -1e-9) {
        yAdditive = 0;
    }
    if (zAdditive < 1e-9 and zAdditive > -1e-9) {
        zAdditive = 0;
    }

    xCoordinate = xCoordinate + xAdditive;
    yCoordinate = yCoordinate + yAdditive;
    zCoordinate = zCoordinate + zAdditive;

    std::cout << xCoordinate << std::endl << yCoordinate << std::endl << zCoordinate << std::endl;
}

void NAGENobject::rotate(double theta, double phi) {
    double circle = Pi*2;
    phiAngle = std::fmod(phiAngle+phi, circle);
    thetaAngle = std::fmod(thetaAngle+theta, circle);
}


float NAGENobject::gravityTick(double tickPerSecond) {
    return (EarthG / tickPerSecond);
}


void NAGENobject::update(double tickPerSecond, int idOfObject) {
    // Update speed based on gravity
    zSpeed -= gravityTick(tickPerSecond);



    // Update position based on speed and time
    xCoordinate += xSpeed / tickPerSecond;
    yCoordinate += ySpeed / tickPerSecond;
    zCoordinate += zSpeed / tickPerSecond;

    // Check if the object has reached the ground
    if (zCoordinate <= zSize / 2) {
        zCoordinate = zSize / 2;
        zSpeed *= -coefOfRestitution;
    }

    std::cout << "ID: " << idOfObject << std::endl;
    std::cout << "x:  " << xCoordinate << "\t" << xSpeed << std::endl;
    std::cout << "y:  " << yCoordinate << "\t" << ySpeed << std::endl;
    std::cout << "z:  " << zCoordinate << "\t" << zSpeed << std::endl;
}
