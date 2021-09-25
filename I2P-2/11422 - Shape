#include <iostream>
#include <math.h>
#include "function.h"

oj::Triangle::Triangle(double edge1, double edge2, double edge3) {
    if(edge1 <= 0 || edge2 <= 0 || edge3 <= 0) {
        setArea(0);
        setPerimeter(0);
        return;
    }
    this->edge1 = edge1;
    this->edge2 = edge2;
    this->edge3 = edge3;
    setPerimeter(edge1+edge2+edge3);
    double s = getPerimeter()/2;
    if((s - edge1 <= 0) || (s - edge2 <= 0) || (s - edge3 <= 0)) setArea(0), setPerimeter(0);
    else setArea(sqrt(s*(s-edge1)*(s-edge2)*(s-edge3)));
}

oj::Rectangle::Rectangle(double width, double height) {
    if(width <= 0 || height <= 0) {
        setArea(0);
        setPerimeter(0);
        return;
    }
    this->width = width;
    this->height = height;
    setArea(width*height);
    setPerimeter(2*(width+height));
}

oj::Circle::Circle(double radius, double pi) {
    if(radius <= 0 || pi <= 0) {
        setArea(0);
        setPerimeter(0);
        return;
    }
    this->radius = radius;
    this->pi = pi;
    setArea(pi*radius*radius);
    setPerimeter(2*pi*radius);
}
