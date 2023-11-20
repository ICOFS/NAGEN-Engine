//
//
// Copyright 2023 Farmat team
//
// Licensed under the FOSL (the "LICENSE.md");
//
//

#include <iostream>
#include <cmath>

#include "NAGENobject.hpp"

int main () {
    NAGENobject Object;
    
    Object.mass = 1; // Kilogram
    
    Object.xCoordinate = 0; // Meter
    Object.yCoordinate = 0; // Meter
    Object.zCoordinate = 1000; // Meter
    
    Object.phiAngle = 0; // Radian
    Object.thetaAngle = 0; // Radian
    
    Object.xSpeed = 0;
    Object.ySpeed = 0;
    Object.zSpeed = 0;
    
    Object.xSize = 0.5;
    Object.ySize = 0.5;
    Object.zSize = 0.5;
    
    
//    // This function calculates the speed and position (points of mass) of a body at every second - gravity.
//    // The function does not take into account air
//    Object.EarthGravityDemo();
//    
//    Object.rotate(3.1415926535, 0);
//    Object.moveStraight(1);
//    // Something like turning 180 and walking 1 meter...
//
//    Object.rotate(3.1415926535, 0);
//    Object.moveStraight(1);
//    // ...and then turn back and walk another 1 meter
     
    
}

