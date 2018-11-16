/* \file camera.h
 * \brief Contains the definition of the camera class
 */

#ifndef FREY_CAMERA_H
#define FREY_CAMERA_H

#include "math/vector.h"

namespace frey{

    /* \class camera camera.h camera/camera.h
     * \brief An abstract representation of a camera in 3d space
     */

    class camera{

        private:
            vector position, direction, right, down;
            unsigned int width, height;

        public:

            /* \brief Constructor for the camera class
             * \param pos the position vector of the camera
             * \param dir the direction vector of the camera
             * \param rht the right vector of the camera
             * \param dwn the down vector of the camera
             * \param w the width of the viewport
             * \param h the height of the viewport
             */
            camera(vector pos, vector dir, vector rht, vector dwn, unsigned int w, unsigned int h);

            /* \brief get_position() returns the position of the camera
             */
            inline vector get_position() { return position; }

            /* \brief get_direction() returns the direction, camera is facing
             */
            inline vector get_direction() { return direction; }

            /* \brief get_right() returns the right vector of the camera
             */
            inline vector get_right() { return right; }

            /* \brief get_down() returns the down vector of the camera
             */
            inline vector get_down() { return down; }

            /* \brief get_width() returns the width of the viewport
             */
            inline unsigned int get_width() { return width; }

            /* \brief get_height() returns the height of the viewport
             */
            inline unsigned int get_height() { return height; }
    };
}

#endif
