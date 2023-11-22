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
    
    Object.xCoordinate = 0;
    Object.yCoordinate = 0;
    Object.zCoordinate = 1000;
    
    Object.phiAngle = 0;
    Object.thetaAngle = 0;
    
    Object.xSpeed = 0;
    Object.ySpeed = 0;
    Object.zSpeed = 0;
    
    Object.xSize = 0.5;
    Object.ySize = 0.5;
    Object.zSize = 0.5;
    
    
//    vertex v1 = {-0.5, -0.5, -0.5};  // Bottom edge
//    vertex v2 = { 0.5, -0.5, -0.5};
//    vertex v3 = { 0.5,  0.5, -0.5};
//    vertex v4 = {-0.5,  0.5, -0.5};
//    vertex v5 = {-0.5, -0.5,  0.5};  // Top edge
//    vertex v6 = { 0.5, -0.5,  0.5};
//    vertex v7 = { 0.5,  0.5,  0.5};
//    vertex v8 = {-0.5,  0.5,  0.5};
//    
//    Object.vertexes.push_back(v1);
//    Object.vertexes.push_back(v2);
//    Object.vertexes.push_back(v3);
//    Object.vertexes.push_back(v4);
//    Object.vertexes.push_back(v5);
//    Object.vertexes.push_back(v6);
//    Object.vertexes.push_back(v7);
//    Object.vertexes.push_back(v8);
    
//    for (const auto& vertex : Object.vertexes) {
//        std::cout << "x: " << vertex.xCoordinate << ", ";
//        std::cout << "y: " << vertex.yCoordinate << ", ";
//        std::cout << "z: " << vertex.zCoordinate << std::endl;
//    }
    
    Object.EarthGravityDemo();
    
//    for (const auto& vertex : Object.vertexes) {
//        std::cout << "x: " << vertex.xCoordinate << ", ";
//        std::cout << "y: " << vertex.yCoordinate << ", ";
//        std::cout << "z: " << vertex.zCoordinate << std::endl;
//    }
    
    
    
    
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

