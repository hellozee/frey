#ifndef FREY_VECTOR_H
#define FREY_VECTOR_H

namespace frey{

    /** \class vector vector.h math/vector.h
     *  \brief An abstract representation of a 3d vector
     *  \details This class is to be used for representing vector in
     *           calculations. Operators +, -, !, *, ^, =, == are implemented.<br>
     *           (+) to be used for adding:<br>
     *              v = v1 + v2 <br>
     *           (!) to be used for negation:<br>
     *              v = !v<br>
     *           (-) to be used for subtraction:<br>
     *              v = v1 - v2<br>
     *           (*) to be used for dot product:<br>
     *              v = v1 * v2<br>
     *           (^) to be used for cross product:<br>
     *              v = v1^v2  <br>
     */

    class vector{
        private:
            double x,y,z;
        public:

            /* \fn vector()
             * \brief An empty constructor for the frey::vector class, <br>
             *        constructs a frey::vector{x : 1.0, y : 1.0, z : 1.0}
             */
            vector();
            
            /* \fn vector(double val)
             * \brief A constructor which takes single value for all the axes, <br>
             *        constructs a frey::vector{x : val, y : val, z : val}
             * \param val double
             */
            vector(double val);
            
            /* \fn vector(double i, double j, double k)
             * \brief A constructor which takes separate values for the axes, <br>
             *        constructs a frey::vector{x : i, y : j, z : k}
             * \param i double for the x-axis
             * \param j double for the y-axis
             * \param k double for the z-axis
             */
            vector(double i, double j, double k);
            
            inline double getx() const { return x; }
            inline double gety() const { return y; }
            inline double getz() const { return z; }

            /* \fn inline double magnitude()
             * \brief magnitude() returns the magnitude of the current vector <br>
             *        which is the square root of the sum of the squares of all <br>
             *        of its elements.
             * \return A double value which is the magnitude
             */
            inline double magnitude();
            
            /* \fn vector normalize()
             * \brief normalize() returns a normalized version of the current vector <br>
             *        which is the current vector divided by its magnitude.
             * \return A nomalized vector 
             */
            vector normalize();

            inline vector operator+(const vector v);
            inline vector operator!();
            inline vector operator-(const vector v);
            inline double operator*(const vector v);
            vector operator^(const vector v);
            void operator=(const vector v);
            inline bool operator==(const vector v) const;
    };
}

#endif
