//
//  vertex.hpp
//  Nagen Engine Framework
//
//  Created by Farmat on 2023-11-21.
//

#pragma once

#ifndef vertex_h
#define vertex_h


/**
 
 To add coordinates, use local coordinates, where 0; 0; 0 - center of mass of the body
 
 */
struct vertex {
    double xCoordinate;
    double yCoordinate;
    double zCoordinate;
};

struct poligon {
    double xCoordinate1;
    double yCoordinate1;
    double zCoordinate1;

    double xCoordinate2;
    double yCoordinate2;
    double zCoordinate2;

    double xCoordinate3;
    double yCoordinate3;
    double zCoordinate3;
};

#endif /* vertex_h */
