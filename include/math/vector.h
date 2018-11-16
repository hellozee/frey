/* \file vector.h
 * \brief Contains the definition of the vector class used for represting 3d vectors
 */
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

            /* \brief An empty constructor for the vector class, <br>
             *        constructs a vector{x : 1.0, y : 1.0, z : 1.0}
             */
            vector();
            
            /* \brief A constructor which takes single value for all the axes, <br>
             *        constructs a vector{x : val, y : val, z : val}
             * \param val double
             */
            vector(double val);
            
            /* \brief A constructor which takes separate values for the axes, <br>
             *        constructs a vector{x : i, y : j, z : k}
             * \param i double for the x-axis
             * \param j double for the y-axis
             * \param k double for the z-axis
             */
            vector(double i, double j, double k);
            
            /* \brief getx() returns the x co-ordinate of the current vector 
             */
            double getx() const { return x; }

            /* \brief gety() returns the y co-ordinate of the current vector 
             */
            double gety() const { return y; }

            /* \brief getz() returns the z co-ordinate of the current vector 
             */
            double getz() const { return z; }

            /* \brief magnitude() returns the magnitude of the current vector <br>
             *        which is the square root of the sum of the squares of all <br>
             *        of its elements.
             * \return A double value which is the magnitude
             */
            double magnitude();
            
            /* \brief normalize() returns a normalized version of the current vector <br>
             *        which is the current vector divided by its magnitude.
             * \return A nomalized vector 
             */
            vector normalize();

            /* \brief overloading the (+) operator for adding two vectors
             */
            vector operator+(const vector v);

            /* \brief overloading the (!) operator for negating the current vector
             */
            vector operator!();

            /* \brief overloading the (-) operator for subtracting one vector from another
             */
            vector operator-(const vector v);

            /* \brief overloading the (*) operator for doing dot product of two vectors
             */
            double operator*(const vector v);

            /* \brief overloading the (^) operator for doing cross product of two vectors
             */
            vector operator^(const vector v);

            /* \brief overloading the (=) as assignment operator
             */
            void operator=(const vector v);

            /* \brief overloading the (==) operator for comparing two vectors for equivalence
             */
            bool operator==(const vector v) const;
    };
}

#endif
