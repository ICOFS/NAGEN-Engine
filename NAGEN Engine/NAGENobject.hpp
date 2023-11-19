//
//  NAGENobject.hpp
//  NAGEN Engine
//
//  Created by Farmat on 2023-11-19.
//

#ifndef NAGENobject_hpp
#define NAGENobject_hpp

#include <stdio.h>

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
    
    void moveStraight(double length);
    void rotate(double phi, double theta);
};

#endif /* NAGENobject_hpp */
