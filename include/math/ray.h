/** \file ray.h
*   \brief Contains the definition of the Ray class
*/

#ifndef FREY_RAY_H
#define FREY_RAY_H

#include "math/vector.h"

namespace frey{
    
    /** \class ray ray.h math/ray.h
    *   \brief An abstract represention of ray
    */

    class ray{
        private:
            vector origin, direction;
        public:
            /** \brief Contructor for the ray class sets the origin and the direction <br>
            *        vector the ray.
            *   \param orig the origin vector
            *   \param dir the direction vector
            */
            ray(vector orig, vector dir);

            /** \brief get_origin() returns the origin vector of the ray
            */
            inline vector get_origin() { return origin; }

            /** \brief get_direction() return the direction vector the ray
            */
            inline vector get_direction() { return direction; }
    };

}

#endif
