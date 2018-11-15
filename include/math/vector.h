#ifndef FREY_VECTOR_H
#define FREY_VECTOR_H

namespace frey{
    class vector{
        public:
            double x,y,z;

            vector();
            vector(double val);
            vector(double i, double j, double k);

            double magnitude();
            vector normalize();

    };
}

#endif
