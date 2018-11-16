/* \file camera.cpp
 */

#include "camera/camera.h"

frey::camera::camera(frey::vector pos, frey::vector dir, frey::vector rht, 
                     frey::vector dwn, unsigned int w, unsigned int h):
    position(pos), direction(dir), right(rht), down(dwn), width(w), height(w)
{ }
