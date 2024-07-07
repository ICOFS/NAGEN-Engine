//
//  mesh.hpp
//  Nagen Engine Framework
//
//  Created by Farmat on 2023-11-21.
//

#pragma once

#ifndef vertex_h
#define vertex_h

struct vertex {
    float xCoordinate;
    float yCoordinate;
    float zCoordinate;
};

struct polygon {
    vertex first;
    vertex second;
    vertex third;
};

struct edge {
    vertex v1;
    vertex v2;
};

#endif /* vertex_h */
