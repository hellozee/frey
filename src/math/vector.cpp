#include "math/vector.h"

#include <cmath>

frey::vector::vector():
    x(1.0),y(1.0),z(1.0)
{

}

frey::vector::vector(double val):
    x(val), y(val), z(val)
{

}

frey::vector::vector(double i, double j, double k):
    x(i),y(j),z(k)
{

}

double 
frey::vector::magnitude()
{
    return sqrt(x*x + y*y + z*z);
}

frey::vector 
frey::vector::normalize()
{
    double mag = this->magnitude();
    int tx = x / mag;
    int ty = y / mag;
    int tz = z / mag;

    return vector(tx,ty,tz);
}
