#ifndef FREY_VECTOR_H
#define FREY_VECTOR_H

namespace frey{
    class vector{
        private:
            double x,y,z;
        public:
            vector();
            vector(double val);
            vector(double i, double j, double k);
            
            inline double getx() const { return x; }
            inline double gety() const { return y; }
            inline double getz() const { return z; }

            double magnitude();
            vector normalize();

            vector operator+(const vector v);
            vector operator!();
            vector operator-(const vector v);
            double operator*(const vector v);
            vector operator^(const vector v);
            void operator=(const vector v);
            bool operator==(const vector v) const;
    };
}

#endif
