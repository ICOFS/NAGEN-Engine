//
//  NAGENobject.cpp
//  NAGEN Engine
//
//  Created by Farmat on 2023-11-19.
//


#include <cmath>
#include <iostream>

#include "NAGENobject.hpp"
#include "globalConsts.h"

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
};


void NAGENobject::rotate(double theta, double phi) {
    double circle = Pi*2;
    phiAngle = std::fmod(phiAngle+phi, circle);
    thetaAngle = std::fmod(thetaAngle+theta, circle);
};


void NAGENobject::EarthGravityDemo() {
    double tick = 0;
//    double locEarthG = EarthG/3*2;
    
    
    while (tick < 15 * tickPerSecond) {
        std::cout << tick/tickPerSecond << std::endl;
        std::cout << "x: " << xCoordinate << " " << xSpeed << std::endl;
        std::cout << "y: " << yCoordinate << " " << ySpeed << std::endl;
        std::cout << "z: " << zCoordinate << " " << zSpeed << std::endl;

        tick++;

        double zCoordinateOld = zCoordinate;

        zSpeed -= EarthG / tickPerSecond;

        if (zCoordinate + zSize <= 0) {
            zSpeed = 0;
        }

        zCoordinate += zSpeed/tickPerSecond;

        if (zCoordinate < 0.5) {
            zCoordinate = 0.5;
        }

        zSpeed = -(zCoordinateOld - zCoordinate)*tickPerSecond;
    }
}
