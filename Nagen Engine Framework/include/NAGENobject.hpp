//
//  NAGENobject.hpp
//  Nagen Engine Framework
//
//  Created by Farmat on 2023-11-19.
//

#pragma once

#ifndef NAGENobject_hpp
#define NAGENobject_hpp

#include <cstdio>
#include <vector>

#include "mesh.hpp"


/**
    The base class of the object.
 
 double xCoordinate — x coordinate relative to the center of the world, meter
 
 double yCoordinate — y coordinate relative to the center of the world, meter
 
 double zCoordinate — z coordinate relative to the center of the world, meter
 
 
 double thetaAngle — Zenith angle value, radian
 
 double phiAngle — Azimuth angle value, radian
 
 
 double xSize — The size of the object along the OX axis from the center of mass, meter
 
 double ySize — The size of the object along the OY axis from the center of mass, meter
 
 double zSize — The size of the object along the OZ axis from the center of mass, meter
 
 
 double mass — Object mass value, kg
 
 
 double xSpeed — Local x-axis velocity value, radian
 
 double ySpeed — Local y-axis velocity value, radian
 
 double zSpeed — Local z-axis velocity value, radian
 
 
 double temperature — Object temperature value, kelvin
 
 */
class NAGENobject {
public:
    double xCoordinate;
    double yCoordinate;
    double zCoordinate;
    
    double phiAngle;
    double thetaAngle;
    
    double xSize;
    double ySize;
    double zSize;
    
    double mass;
    
    double xSpeed;
    double ySpeed;
    double zSpeed;
    
    double temperature;
    
    std::vector<mesh> vertexes;
    std::vector<poligon> poligons;
    
    /**
     This function demonstrates the movement of a body along the Oz axis.
      
     * @param
     length Value in meters. Moves the object n meters forward along the oZ axis. Allows negative values.
     */
    void moveStraight(double length);
    
    /**
     This function demonstrates the rotation of the body.
      
     * @param
     
     theta Value in radians. Zenith angle of rotation. Allows negative values.
     
     * @param
     phi Value in radians. Azimuthal rotation angle. Allows negative values.
     
     
     */
    void rotate(double theta, double phi);
    
    /**
     This function demonstrates a body falling from a height.

     Values such as speed and body position are displayed for each second separately.

     The function does not take into account air resistance.
     */
    void EarthGravityDemo(double tickPerSecond);
    
    
    void gravityTick(double tick, double tickPerSecond, int idOfObject);

    void update(double tickPerSecond);
};

#endif /* NAGENobject_hpp */
