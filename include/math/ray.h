/* \file ray.h
 * \brief Contains the definition of the Ray class
 */

#ifndef FREY_RAY_H
#define FREY_RAY_H

#include "math/vector.h"

namespace frey{
    
    /* \class ray ray.h math/ray.h
     * \brief An abstract represention of ray
     */

    class ray{
        private:
            vector origin, direction;
        public:
            ray(vector orig, vector dir);
    };

}

#endif
