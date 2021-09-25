#include <iostream>
#include "function.h"

oj::Sphere::Sphere(double r, double p) {
    if(r <= 0 || p <= 0) {
        setVolume(0);
        return;
    }
    radius = r;
    pi = p;
    setVolume(4.0/3.0*pi*radius*radius*radius);
}

oj::Cone::Cone(double r, double h, double p) {
    if(r <= 0 || h <= 0 || p <= 0) {
        setVolume(0);
        return;
    }
    radius = r;
    height = h;
    pi = p;
    setVolume(1.0/3.0*pi*radius*radius*height);
}

oj::Cuboid::Cuboid(double l, double w, double h) {
    if(l <= 0 || w <= 0 || h <= 0) {
        setVolume(0);
        return;
    }
    length = l;
    width = w;
    height = h;
    setVolume(length*width*height);
}

oj::Cube::Cube(double a) : Cuboid(a,a,a) {}
