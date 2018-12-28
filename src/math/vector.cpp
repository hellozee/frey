/* \file vector.cpp
 */

#include "math/vector.h"

#include <cmath>

frey::vector::vector():
    x(1.0),y(1.0),z(1.0)
{ }

frey::vector::vector(double val):
    x(val), y(val), z(val)
{ }

frey::vector::vector(double i, double j, double k):
    x(i),y(j),z(k)
{ }

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

frey::vector
frey::vector::operator+(const frey::vector v)
{
    return frey::vector(x+v.getx(), y+v.gety(), z+v.getz());
}

frey::vector
frey::vector::operator!()
{
    return frey::vector(-x,-y,-z);
}

frey::vector
frey::vector::operator-(const frey::vector v)
{
    return frey::vector(x-v.getx(), y-v.gety(), z-v.getz());
}

double
frey::vector::operator*(const frey::vector v)
{
    return x*v.getx() + y*v.gety() + z*v.getz();
}

frey::vector
frey::vector::operator*(const double val)
{
    return frey::vector(x*val, y*val, z*val);
}

frey::vector
frey::vector::operator/(const double val)
{
    return frey::vector(x/val, y/val, z/val);
}

frey::vector
frey::vector::operator^(const frey::vector v)
{
    double tx = y * v.getz() - z * v.gety();
    double ty = z * v.getx() - x * v.getz();
    double tz = x * v.gety() - y * v.getx();
    return frey::vector(tx,ty,tz);
}

void
frey::vector::operator=(const frey::vector v)
{
    x = v.getx();
    y = v.gety();
    z = v.getz();
}

bool
frey::vector::operator==(const frey::vector v) const 
{
    return x == v.getx() && y == v.gety() && z == v.getz();
}

frey::vector
frey::vector::operator+=(const frey::vector v)
{
    return *this + v;
}

frey::vector
frey::vector::clamp()
{
    //lambdas look sexy
    auto clamp_double = [](double x){
        if (x < 0) return 0.0;
        if (x > 1) return 1.0;
        return x;
    };

    return frey::vector(clamp_double(x), clamp_double(y), clamp_double(y));
}

std::ostream&
frey::operator<< (std::ostream &out, const frey::vector &v)
{
    out << "frey::vector{ x: " << v.getx() << ", y: " << v.gety()
        << ", z: " << v.getz() << " }" <<std::endl;
    return out;
}
